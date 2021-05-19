#include<vector>
#include<iostream>
#include<initializer_list>
#include<memory>
#include<stdexcept>
using std::vector; using std::cout; using std::string;
//StrBlobPtr throws an exception on attempts to access a  nonexistent element
class StrBlobPtr;
class StrBlob {
	friend bool operator==(const StrBlob&,const StrBlob&);
	friend bool operator!=(const StrBlob&,const StrBlob&);
		friend bool operator>(const StrBlob&,const StrBlob&);
	friend bool operator<(const StrBlob&,const StrBlob&);
	friend class StrBlobPtr;
public:

	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<string>i1);
    
	size_type size()const { return data->size(); }
	//add and remove elements
	void push_back(const string& t) { data->push_back(t); }
	void pop_back();
	//element access
	string& front()const;
	string& back()const;
	string& front();
	string& back();

	//these members can't be defined until StrBlob and StrBlobPtr are defined
	StrBlobPtr begin();
	StrBlobPtr end();
	std::string& operator[](size_t sz)
	{
		auto v_str=(*(data.get()));
		return v_str[sz];
	}

	const std::string& operator[](size_t sz)const
	{
		auto v_str=(*(data.get()));
		return v_str[sz];
	}

	
private:
	std::shared_ptr<vector<string>>data;
	//throws msg if data[i] isn't valid
	void check(size_type i, const string& msg)const;
};

//Starblob constructors
//Each constructor uses its constructor initializer list
StrBlob::StrBlob() :data(std::make_shared<vector<string>>()) {}
StrBlob::StrBlob(std::initializer_list<string>i1) : data(std::make_shared<vector<string>>(i1)) {}

//Element Access Members
void StrBlob::check(size_type i, const string& msg)const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}


string& StrBlob::front()const
{
	//if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	std::cout << "Const front called\n";
	return data->front();
}

string& StrBlob::front()
{
	//if the vector is empty, check will throw
	check(0, "front on empty StrBlob");
	std::cout << "Ordinary front called\n";//printed out as I expected
	return data->front();
}

string& StrBlob::back()const
{
	check(0, "back on empty StrBlob");
	std::cout << "const back called\n";//printed out as I expected
	return data->back();
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	std::cout << "Ordinary back called\n";//printed out as I expected
	return data->back();
}


void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");//printed out as I expected
	data->pop_back();
}

class StrBlobPtr {
	friend bool operator==(const StrBlobPtr&,const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&,const StrBlobPtr&);
	friend bool operator<(const StrBlobPtr&,const StrBlobPtr&);
	friend bool operator>(const StrBlobPtr&,const StrBlobPtr&);
    friend StrBlobPtr& operator+(StrBlobPtr&,size_t);
    friend StrBlobPtr& operator-(StrBlobPtr&,size_t);
public:
//increment and decrement
StrBlobPtr& operator++();//prefix operators
StrBlobPtr operator++(int);//postfix operators
StrBlobPtr& operator--();//prefix operators
StrBlobPtr operator--(int);//postfix operators


	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	std::string& deref()const;
	StrBlobPtr& incr();//prefix version

	std::string& operator[](size_t sz)
	{
		vector<string>vec=*(wptr.lock().get());
		return vec[sz];
	}
		const std::string& operator[](size_t sz)const
	{
		const vector<string>vec=*(wptr.lock().get());
		return vec[sz];
	}

private:
	//check returns a shared_ptr to the vector if the check succeeds
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&)const;

	//store a weak_ptr, which means the underlying vector might be destroyed.
	std::weak_ptr<std::vector<std::string>>wptr;
	std::size_t curr;
	//Note:
	//It is worth noting that we cannot bind a StrBlobPtr to a const StrBlob object.
	//This restriction follows
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg)const
{
	auto ret = wptr.lock();//Is the vector still around?
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;//otherwise, return a shared_ptr to the vector.
}


//The deref member calls check to verify that it is safe to use the vector
//and that curr is in range:
std::string& StrBlobPtr::deref()const
{
	auto p = check(curr, "dereference past end");
	//If check succeeds, p is shared_ptr to the vector to which this StrBlobPtr points.
	return (*p)[curr];//(*p) is the vector to which this object points.
}


//The incr member also calls check:
//prefix: return a reference to the incremented object:
StrBlobPtr& StrBlobPtr::incr()
{
	//if curr already points past the end of the container,can't increment it
	check(curr+1, "increment past end of STrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

//prefix: return a reference to the incremented/decremented object
StrBlobPtr& StrBlobPtr::operator++()
{
    //if curr already points past the end of the container, can't increment it
    check(curr,"increment past end of StrBlobPtr");
    ++curr;//advance the current state
    return *this;
}
StrBlobPtr& StrBlobPtr::operator--()
{
    //if curr is zero, decrement it will yield an invalid subscirpt
    --curr;
    check(curr,"increment past end of StrBlobPtr");
    return *this;
}

//The postfix versions have to remember the current state
//of the object before incrementing the object
//postfix: increment/decrement the object but return the unchanged value
//Note that the int is unused, so we do not give it a name.
/*
*To be consistent with the built-in operators, the postfix operators should
*return the old(unincremented or undecremented) value. That value is returned
*as a value, not a reference.
*/
StrBlobPtr StrBlobPtr::operator++(int)
{
    //no check needed here; the call to prefix increment will do the work;
    StrBlobPtr ret=*this;//save the current value
    ++*this;//advance one element; prefix ++ checks the increment
    return ret;//return the saved state
}
StrBlobPtr StrBlobPtr::operator--(int)
{
    //no check needed here; the call to prefix decrement will do the check
    StrBlobPtr ret=*this;//save the current value
    ++*this;//move backward one element; prefix -- checks the decrement
    return ret;//return the saved state
}

StrBlobPtr& operator+(StrBlobPtr& curr,size_t sz)
{
    for(size_t i=0;i<sz;i++)
    curr.operator++();
    return curr;
}

StrBlobPtr& operator-(StrBlobPtr& curr,size_t sz)
{
    for(size_t i=0;i<sz;i++)
    curr.operator--();
    return curr;
}

int main()
{
  StrBlob sb({"crucial","fact_check","Europa","Europe","Europee","Ou_Zhou","Ou_Shuu"});
  StrBlobPtr sbp(sb);//sbp points to the vector inside sb
  auto sbp1=sbp.operator++(0);//call postfix operator++
  auto sbp2=sbp.operator++();//call prefix operator++
  std::cout<<sbp.deref()<<std::endl;
   std::cout<<sbp1.deref()<<std::endl;
    std::cout<<sbp2.deref()<<std::endl;
    auto sbp3=sbp2+2;
    std::cout<<sbp2.deref()<<std::endl;
    auto sbp4=sbp3-3;
     std::cout<<sbp4.deref()<<std::endl;
}