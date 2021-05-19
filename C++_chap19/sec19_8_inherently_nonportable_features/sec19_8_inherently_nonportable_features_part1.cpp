//To support low-level programming, C++ defines some features that are inherently
//nonportable. ----machine-specific
//1: size of the arithmetic types vary across machines.
//2:extra two: bit-fields volatile qualifier

/*bit-fields*/
//A class can defined a nonstatic data member as a bit-field. A bit-field holds a 
//specific number of bits. Bit-fields are normally used when a program needs to pass
//binary data to another program or to a hardware device.
#include<iostream>
typedef unsigned int Bit;
class File{
    Bit mode:2;//mode has two bits
    Bit modified:1;//modified has 1 bit
    Bit prot_owner:3;//prot_owner has 3 bits
    Bit prot_group:3;//prot_group has 3 bits
    Bit prot_world:3;//prot_world has 3 bits
    //operations and data members of File
    public:
    //file modes specified as octal literals.
    enum modes{READ=01,WRITE=02,EXECUTE=03};
    File &open(modes);
    void close();
    void write();
    bool isRead()const;
    void read();
    void unread();
    void setWrite();
};
//The mode bit-field has two bits, modeified only one, and the other members each have
//three bits. Bit-fields defined in consecutive order within the class body are, if possible,
//packed within adjacnent bits of the same integer, thereby providing for storage compaction.
//For example, in the preceding declaration, the five bit-fields will (probably) be stored
//in a single unsigned int. Whether and how the bits are packed into the integer is machine
//depedent.
//The address-of operator could not be applied to a bit-field, so there can be no pointers 
//referring to class bit-fields.
/*Using bit-fields*/
void File::write(){
    modified=1;
}
void File::close(){
    if(modified)modified=0;
}
void File::unread(){
    if(mode&READ)mode^=READ;
}
void File::read(){
    if(mode^READ)mode|=READ;
}
File& File::open(File::modes m){
    mode|=READ;//set the READ bit by default
    //other processing
    if(m&WRITE)//if opening READ and WRITE
    mode^=WRITE;
    //processing to open the file in read/write mode
    return *this;
}
//classes that define bit-field members also usually define a set of inline
//functions to test and set the value of the bit-field
inline bool File::isRead()const{return mode&READ;}

inline void File::setWrite(){mode|=WRITE;}
int main(){
    File item1;
    std::cout<<std::boolalpha;
    std::cout<<item1.isRead();
    item1.unread();
     std::cout<<std::endl<<item1.isRead();
     item1.read();
     std::cout<<std::endl<<item1.isRead();
     item1.unread();
      std::cout<<std::endl<<item1.isRead();
      item1.open(File::READ);
       std::cout<<std::endl<<item1.isRead();
}
/*
false
false
true
false
true
*/