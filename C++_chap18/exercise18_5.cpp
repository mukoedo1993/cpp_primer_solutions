#include<stdexcept>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
void fcn()
{
   
    throw out_of_range("out of range__LINE__") ;
}
int main(){
    try{
       fcn();
    }catch(const range_error &ob1)
    {
      cerr<<ob1.what();
      abort();
    }catch(const underflow_error &ob1)
    {
      cerr<<ob1.what();
      abort();
    }
    catch(const overflow_error &ob1)
    {
      cerr<<ob1.what();
      abort();
    }catch(const runtime_error &ob1)
    {
      cerr<<ob1.what();
      abort();
    }catch(const bad_cast &ob1)
    {
      cerr<<ob1.what();
      abort();
    }catch(const bad_alloc &ob1)
    {
      cerr<<ob1.what();
      abort();
    }catch(const domain_error &ob1)
    {
      cerr<<ob1.what();
      abort();
    }catch(const invalid_argument &ob1)
    {
      cerr<<ob1.what();
      abort();
    }
    catch(const out_of_range &ob1)
    {
      cerr<<ob1.what();
      abort();
    } catch(const length_error &ob1)
    {
      cerr<<ob1.what();
      abort();
    }catch(const logic_error &ob1)
    {
      cerr<<ob1.what();
      abort();
    }catch(const exception &ob1)
    {
      cerr<<ob1.what();
      abort();
    }
    std::cout<<"this line:"<<__LINE__<<endl;
}