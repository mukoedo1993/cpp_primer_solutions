/*
seekp(off,from) Reposition the marker for an input or output stream integral
number off characters ahead of behind from. from can be one of
beg, seek relative to the beginning of the stream
cur, seek relative to the current position of the stream
end, seek relative to the end of the stream
tellg() return the current position of the amrker in an input stream (tellg)
or an output stream(tellp)
tellp()  
*/

#include<iostream>
#include<fstream>

using namespace std;
int main()
{
    //open for input and output and preposition file pointers to EOF
    //file mode agrument
    fstream inOut("copyOut",
    fstream::ate|fstream::in|fstream::out);
    if(!inOut){
        cerr<<"Unable to open file!"<<endl;
        return EXIT_FAILURE;
    }
    //inOut is opened in ate mode, so it sarts out positioned at the end
    fstream::pos_type end_mark=inOut.tellg();//remember original EOF position
    inOut.seekg(0,fstream::beg);//reposition to the start of the file
    size_t cnt=0;//accumulator for the byte count
    string line;//hold each line of input
    //while we haven't hit an error and are still reading the original data
    while(inOut&&inOut.tellg()!=end_mark
    &&getline(inOut,line)) {//and can get another line of input
     cnt+=line.size()+1;//add 1 to account for the newline
     fstream::pos_type mark=inOut.tellg();//remember the read position
     inOut.seekp(0,fstream::end);//set the write marker to the end
     inOut<<cnt;//write the accumulate length
     //print a separator if this is not the last line
     if(mark!=end_mark)inOut<<" ";
     inOut.seekg(mark);//restore the read positions
     
    }
    inOut.seekp(0,fstream::end);//seek to the end
    inOut<<"\n";//write a new line at EOF
    return 0;

}
//original input:
/*
abcd
efg
hi
j

*/