#include"sec15_8_1_writing_a_basket_class.h"

int main(){

    /*holding the pointers*/
    Basket bsk;
    bsk.add_item(std::make_shared<Quote>("123",45));
    bsk.add_item(std::make_shared<Bulk_quote>("345",45,3,.15));
    bsk.add_item(std::make_shared<Quote>("346",93));
    auto rslt1=bsk.total_receipt(std::cout);
    std::cout<<std::endl<<rslt1<<std::endl;
    //new Quote(sale)
    //However, sale might refer to a Bulk_quote object, in which object, that
    //object will be sliced down.
}
/*

ISBN: 123# sold: 1 total due:45
ISBN: 345# sold: 1 total due:45
ISBN: 346# sold: 1 total due:93
Total Sale: 183

183

*/