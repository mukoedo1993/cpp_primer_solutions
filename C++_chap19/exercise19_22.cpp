#include<iostream>
#include <string>
using std::string;
using std::istream;
using std::ostream;
struct Sales_data;
//template<class T>class std::hash;
Sales_data operator+(Sales_data lhs, const Sales_data &rhs);
struct Sales_data {
	friend class std::hash<Sales_data>;
    friend std::ostream& operator<<(std::ostream& ,const Sales_data &);
    friend std::istream& operator>>(std::istream &, Sales_data &);
	~Sales_data() = default;
	//copy control: use defaults
	Sales_data(const Sales_data&) = default;
    Sales_data(Sales_data&&)=default;
    //exercise19_13:
   static const std::string Sales_data::* ex19_13(){
          return &Sales_data::bookNo;
    }
    private:
	std::string bookNo;
    public:
	unsigned units_sold = 0;
	double revenue = 0.0;
	Sales_data& operator=(const Sales_data& rhs);
	Sales_data() = default;
	Sales_data(const std::string& s) :bookNo(s) {} //case a
     
	Sales_data(const std::string& s, unsigned n, double p = 81.0) :
		bookNo(s), units_sold(n), revenue(p* n) {}//case b
   Sales_data operator+=(const Sales_data &Ob1)
{
    *this=*this+Ob1;
    return (*this); 
}

Sales_data& operator=(const std::string& str)
{
    this->bookNo=str;
    return *this;
}

	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}


	double ave_price()const;

	Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
	{
		Sales_data sum = lhs;//copy data members from lhs into sum
		sum.combine(rhs);//add data members from rhs into sum
		return sum;
	}
};

Sales_data operator+(Sales_data lhs, const Sales_data &rhs)
	{
		Sales_data item;
		item.units_sold=lhs.units_sold+rhs.units_sold;
		item.isbn()=lhs.isbn();
		item.revenue=lhs.revenue+rhs.revenue;
		return item;
	}

//
//copy-assignment operator(=)
Sales_data& Sales_data::operator=(const Sales_data& rhs)
{
	bookNo = rhs.bookNo;//calls the string::operator=
	units_sold = rhs.units_sold;//uses the built-in int assignment
	revenue = rhs.revenue;//uses the built-in double assignment
	return *this;//return a reference to this object
}

//The overloads of operator>> and operator<< that take a std::istream& or std::ostream& 
//as the left hand argument are known as insertion and extraction operators. 
//Since they take the user-defined type as the right argument (b in a@b), 
//they must be implemented as non-members.
std::ostream& operator<<(std::ostream& os,const Sales_data &Ob1){
    os<<"bookNo is:"<<Ob1.bookNo<<"\n units sold: "<<Ob1.units_sold<<"\nrevenue is: "<<Ob1.revenue
	<<std::endl;
    return os;
}

std::istream& operator>>(std::istream &is, Sales_data &Ob1)
{
	
	double price;//no need to initaialze; we'll read the price before we use it.
    is>>Ob1.bookNo>>Ob1.units_sold>>price;
	if(is)//check that the input succeed
	Ob1.revenue=Ob1.units_sold*price;
	else
	{
		std::cout<<"Failure!\n";
		Ob1=Sales_data();//input failed: give the object the default state
	}
    return is;
}

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

bool compareIsbn1(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}
class Token{
    public:
    friend  std::ostream& operator<<(std::ostream&os,const Token& tk){
        if(tk.tok==INT)std::cout<<"Type Int!: value is: "<<tk.ival<<'\n';
        else if(tk.tok==CHAR)std::cout<<"Type char! value is: "<<tk.cval<<'\n';
        else if(tk.tok==DBL)std::cout<<"Type is double! value is: "<<tk.dval<<'\n';
        else if(tk.tok==STR)std::cout<<"Type is library string! value is: "<<tk.sval<<'\n';
        else if(tk.tok==ITEM)std::cout<<"Type is Sales_data! values are: \n"<<tk.item<<'\n';
        else throw std::bad_alloc();
        return os;
    }
    //copy control needed because our class has a union with a string emmber
    //defining the move constructor and move assignment operator is left as an exercise
    Token():tok(INT),ival(0){}
    Token(const Token&t):tok(t.tok){copyUnion(t);}
    Token(Token&&t):tok(t.tok){moveUnion(std::forward<Token>(t));}
    Token &operator=(const Token&);
    Token &operator=(Token&&);
    //If the nunion holds a string. we must destroy it;
    ~Token(){using std::string;
        if(tok==STR)sval.~string();}
        //assignment operators to set the differing members of the union
        Token &operator=(const std::string&);
        Token &operator=(char);
         Token &operator=(int);
          Token &operator=(double);
          Token &operator=(const Sales_data&);
    private:
    enum{INT,CHAR,DBL,STR,ITEM}tok;//discriminant


    union{
char cval;int ival;
double dval;
Sales_data item;
std::string sval;
    };//each Token object has an nunamed member of this unnamed union type
    //check the discriminant and copy the union mmeber as appropriate
    void copyUnion(const Token&);
    void moveUnion(Token&&);
};
/*Managing the discriminant and Destroying the string*/
Token &Token::operator=(int i){
    using std::string;
    if(tok==STR)sval.~string();//if we have a string,free it
    if(tok==ITEM)item.~Sales_data();//if we a Sales_data, free it.
    ival=i;//assign to the approrpiate member
    tok=INT;//assign to the appropriate member
    return *this;//update the discriminant
}

Token &Token::operator=(double d){
    using std::string;
    if(tok==STR)sval.~string();//if we have a string,free it
    if(tok==ITEM)item.~Sales_data();//if we have a sales_data,free it.
    dval=d;//assign to the approrpiate member
    tok=DBL;//assign to the appropriate member
    return *this;//update the discriminant
}
Token &Token::operator=(char c){
    using std::string;
    if(tok==STR)sval.~string();//if we have a string,free it
    if(tok==ITEM)item.~Sales_data();
    cval=c;//assign to the approrpiate member
    tok=CHAR;//assign to the appropriate member
    return *this;//update the discriminant
}
Token& Token::operator=(const std::string&s){
    if(tok==STR)//if we already hold a string, just do an assignment
    sval=s;
    else 
    new(&sval)std::string(s);//otherwise construct a string
    if(tok==ITEM)
    item.~Sales_data();
    tok=STR;//update the discriminant
    return *this;
}
Token& Token::operator=(const Sales_data&s){
    if(tok==ITEM)//if we already hold a Sales_data, just do an assignment
    item=s;
    else 
    new(&item)Sales_data(s);//otherwise construct a Sales_data
    using std::string;
    if(tok==STR)
    sval.~string();
    tok=ITEM;//update the discriminant
    return *this;
}
/*Managing union members that require copy control*/
//When we call copyUnion from the copy constructor, the union member will
//have been default-initialized, meaning that the first member of the union will
//have been initialized. Because our string is not the first member, we know that the 
//union member doesn't hold a string. In the assignment operator, it is possible that the union
//already holds a string. We'll handle that case directly in the assignment operator.
//That way copyUnion can assume that if its parameter holds astring, copyUnion must construct
void Token::copyUnion(const Token&t){
    switch(t.tok){
        case Token::INT: tok=INT;ival=t.ival;break;
        case Token::CHAR: tok=CHAR;cval=t.cval;break;
        case Token::DBL: tok=DBL;dval=t.dval;break;
        case Token::STR: tok=STR; new(&sval)std::string(t.sval);break;
        case Token::ITEM: tok=ITEM;new(&item)Sales_data(t.item);break;
        default: throw std::bad_alloc();break;
    }
}
void Token::moveUnion( Token&&t){
    switch(t.tok){
        case Token::INT: tok=INT;ival=std::move(t.ival);break;
        case Token::CHAR: tok=CHAR;cval=std::move(t.cval);break;
        case Token::DBL: tok=DBL;dval=std::move(t.dval);break;
        case Token::STR: tok=STR; new(&sval)std::string(std::move(t.sval));break;
        case Token::ITEM: tok=ITEM; new(&item)Sales_data(std::move(t.item));break;
        default:throw std::bad_alloc();break;
    }
}

Token &Token::operator=(const Token&t){
    //If the object holds a string and t doesn't, we have to free the old string
    using std::string;
    
    if(tok==STR&&t.tok!=STR)sval.~string();
    if(tok==ITEM&&t.tok!=ITEM)item.~Sales_data();
    if((tok==t.tok==STR))
    sval=t.sval;
    else if(tok==t.tok==ITEM)
    item=t.item;
    else 
    copyUnion(t);
     tok=t.tok;
    return *this;
}
Token& Token::operator=(Token&&t){
    if(this==&t){std::cout<<"Warning: move oneself!\n";
        return *this;}
     using std::string;
    if(tok==STR&&t.tok!=STR)sval.~string();
    if(tok==ITEM&&t.tok!=ITEM)item.~Sales_data();
    if((tok==t.tok==STR))
    sval=std::move(t.sval);
    else if(tok==t.tok==ITEM)
    item=std::move(t.item);
    else 
    moveUnion(std::forward<Token>(t));
     tok=t.tok;
    return *this;
}


int main(){
  Token tk1,tk2,tk3;
  tk1='c';
   tk2=tk1;
   tk3=std::move(tk1);
   std::cout<<tk1<<tk2<<tk3;
   //Type char! value is: cType char! value is: cType char! value is: 'c'


Token tk4,tk5,tk6;
double d=3.14;tk4=d;
tk1=tk4;tk5=tk4;tk6=std::move(tk4);

std::cout<<std::endl<<tk1<<tk4<<tk5<<tk6;
/*
Type is double! value is: 
3.14Type is double! value is: 3.14
Type is double! value is: 3.14
Type is double! value is: 3.14
*/

Token tk7,tk8,tk9;
tk7="str";
tk1=tk7;tk8=tk7;
std::cout<<tk1<<tk7<<tk8<<std::endl;
tk9=std::move(tk8); 
std::cout<<tk9<<tk8<<std::endl;//OK,here tk8 is blank.
Token tk10(std::move(tk9));
std::cout<<tk10<<tk9<<std::endl;//OK: here tk9 is blank.

Token tk11;
tk1=14;
tk11=tk1;
Token tk12(tk11);
Token tk13(std::move(tk12));
tk7=std::move(tk13);
std::cout<<tk1<<tk11<<tk12<<tk13<<tk7;//OK. All are 14.

Sales_data item1("shd",12,8.3);
Token tk14; tk1=item1; tk2=std::move(tk1);
tk14=item1;
tk2=tk2;//copy assignment
tk14=std::move(tk14);//move assignment to itself

std::cout<<tk1<<tk2<<tk14;
}

/*

Type char! value is: c
Type char! value is: c
Type char! value is: c

Type is double! value is: 3.14
Type is double! value is: 3.14
Type is double! value is: 3.14
Type is double! value is: 3.14
Type is library string! value is: str
Type is library string! value is: str
Type is library string! value is: str

Type is library string! value is: str
Type is library string! value is: 

Type is library string! value is: str
Type is library string! value is: 

Type Int!: value is: 14
Type Int!: value is: 14
Type Int!: value is: 14
Type Int!: value is: 14
Type Int!: value is: 14
Warning: move oneself!
Type is Sales_data! values are: 
bookNo is:
 units sold: 12
revenue is: 99.6

Type is Sales_data! values are: 
bookNo is:shd
 units sold: 12
revenue is: 99.6

Type is Sales_data! values are: 
bookNo is:shd
 units sold: 12
revenue is: 99.6
*/