#include<iostream>
template<class elemType>class ListItem{};
template <class elemType>class List{
    public:
    List<elemType>(){}
    List<elemType>(const List<elemType>&){}
    List<elemType>&operator=(const List<elemType>&orig){*this=orig;return *this;}
    ~List(){}
    void insert(ListItem<elemType> *ptr,elemType value){std::cout<<value<<std::endl;}
    private:
    ListItem<elemType> *front,*end;
    public:
    void insert1(const elemType&)const;
};

template<typename ele>void List<ele>::insert1(const ele& ele1)const
{
    std::cout<<"\nwe call template<typename ele>\n";
    std::cout<<"void List<ele>::insert1(const ele& ele1)const\n";
}
int main()
{
   ListItem<std::string>L_str,*L_str1=nullptr;
   List<std::string>().insert(L_str1,std::string("hedks"));//hedks
   //We create a temporary object of List above.
    List<std::string>().insert1("djf");
} 
/*
hedks

we call template<typename ele>
void List<ele>::insert1(const ele& ele1)const
*/