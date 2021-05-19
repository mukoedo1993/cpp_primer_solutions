#include<iostream>
/*
To keep track of what type of value the union which holds a non-trivial class
member holds, we usually define a separate object known as a discriminant.
*/

//The only function our class will define are the default constructor, the
//copy-control members, and a set of assignment operators that can assign a value
//of one of our union's types to the union member:
class Token{
    public:
    friend  std::ostream& operator<<(std::ostream&os,const Token& tk){
        if(tk.tok==INT)std::cout<<"Type Int!: value is: "<<tk.ival<<'\n';
        else if(tk.tok==CHAR)std::cout<<"Type char! value is: "<<tk.cval<<'\n';
        else if(tk.tok==DBL)std::cout<<"Type is double! value is: "<<tk.dval<<'\n';
        else if(tk.tok==STR)std::cout<<"Type is library string! value is: "<<tk.sval<<'\n';
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
       
    private:
    enum{INT,CHAR,DBL,STR}tok;//discriminant


    union{
char cval;int ival;
double dval;
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
    ival=i;//assign to the approrpiate member
    tok=INT;//assign to the appropriate member
    return *this;//update the discriminant
}

Token &Token::operator=(double d){
    using std::string;
    if(tok==STR)sval.~string();//if we have a string,free it
    dval=d;//assign to the approrpiate member
    tok=DBL;//assign to the appropriate member
    return *this;//update the discriminant
}
Token &Token::operator=(char c){
    using std::string;
    if(tok==STR)sval.~string();//if we have a string,free it
    cval=c;//assign to the approrpiate member
    tok=CHAR;//assign to the appropriate member
    return *this;//update the discriminant
}
Token& Token::operator=(const std::string&s){
    if(tok==STR)//if we already hold a string, just do an assignment
    sval=s;
    else 
    new(&sval)std::string(s);//otherwise construct a string
    tok=STR;//update the discriminant
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
    }
}
void Token::moveUnion( Token&&t){
    switch(t.tok){
        case Token::INT: tok=INT;ival=std::move(t.ival);break;
        case Token::CHAR: tok=CHAR;cval=std::move(t.cval);break;
        case Token::DBL: tok=DBL;dval=std::move(t.dval);break;
        case Token::STR: tok=STR; new(&sval)std::string(std::move(t.sval));break;
    }
}

Token &Token::operator=(const Token&t){
    //If the object holds a string and t doesn't, we have to free the old string
    using std::string;
    if(tok==STR&&t.tok!=STR)sval.~string();
    if(tok==STR&&t.tok==STR)sval=t.sval;
    else
    copyUnion(t);
    tok=t.tok;
    return *this;
}
Token& Token::operator=(Token&&t){
    if(this==&t)return *this;
    using std::string;
    if(tok==STR&&t.tok!=STR)sval.~string();
    if(tok==STR&&t.tok==STR)sval=std::move(t.sval);
    else if(tok!=STR&&t.tok==STR)new(&sval)string(std::move(t.sval));
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
}


//All results:
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
*/