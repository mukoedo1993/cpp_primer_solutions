
template<class T>int compare(const T&lhs,const T&rhs)
{
    return 1;
}


int main()
{
    //(a):
    //compare("hi","world");
    /*
    no matching function for call to ‘compare(const char [3], const char [6])’
    */
   //(b):
   compare("bye","dad");//ok
   //we are comparing char[3] and char[3] NOW.
}