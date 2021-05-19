namespace Exercise{
    int ivar=0;
    double dvar=0;
    const int limit=1000;
}

int ivar=0;
//position 1
//using namespace directive of Exercise here;
void manip()
{
    //position 2
    //using namespace Exercise;
    double dvar=3.1416;
    int iobj=limit+1;
    ++ivar;//If we use position 1, we will get two error messages:
    //reference to ‘ivar’ is ambiguous
    //"ivar" is ambiguous
    //Same for position 1

    ++::ivar;
}

int main()
{
    
}