#include<iostream>
inline
namespace FifthEd{
    //namespace for the code from the Primer Fifth Edition
}


namespace FifthEd{//implicitly inline
    class Item_base{
        public:
        Item_base(){
          std::cout<<"FifthEd::Item_base::Item_base()\n";
        }
        /*...*/};
    class Query_base{/*...*/};
    //other code from the fourth edition
}