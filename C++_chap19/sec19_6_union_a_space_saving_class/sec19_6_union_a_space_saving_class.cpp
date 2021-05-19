//A union can specify protection labels to make members public, private,
//protected. By default, like structs, members of a union are public.

//Define a union
//Union offer a convenient way to represent a set of mutually exclusive values of
//different types.

//objects of type Token have a single member, which could be of any of the listed
//types
union Token{
    //members are public by default
    public:
    char cval;
    int ival;
    double dval;

};
/*Anonymous unions*/
//An anonymous union is an unnamed union that does not include any declarations
//between the close curly that ends its body and the semicolon that ends the union
//definition. When we define an annonymous union the compiler automatically creates an unamed object of
//the newly defined union type:
static union{//anonymous union
char cval;
int ival;
double dval;
};




int main(){
    static union{
     char cval1;
     int ival1;
     double dval1;
    };
    /*Using a union Type*/
Token first_token={'a'};//initializes the cval member
Token last_token;//uninitialized Token object
Token *pt=new Token;//pointer to an uninitialized Token object

last_token.cval='z';
pt->ival=42;
cval1='t';
}