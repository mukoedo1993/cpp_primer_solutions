#include<iostream>
//(a):
struct CAD{};
struct Vehicle{};
struct CADVehilc:CAD,private Vehicle{};
//Sequence:
//CAD::CAD->Vehicle::Vehicle->CADVehilc::CADVehilc
//CAD::~CAD<-Vehicle::~Vehicle<-CADVehilc::CADVehilc

//(b):
struct List{};
//struct Db1List:List,List{};//duplicate base type 'List' invalid
struct Db1List:List{};

//(c):
class iostream:public std::istream,public std::ostream{};//ok here
//class iostream will take istream's construtcor to construct std::istream's subobject.
//And then, it will take std::ostream's constructor to construct std::ostream's part of
//subobject.
//Inverse sequence for destructor
int main()
{
   iostream ios;//ok

   
}