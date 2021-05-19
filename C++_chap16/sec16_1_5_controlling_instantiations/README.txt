On Ubuntu, you must run the Terminal to make use of those three files.

The file Application.o will contain instantiations for Blob<int>, along with the initializer_list and copy constructors for that class. The compare<int>
function and Blob<std::string>class will not be instantiated in that file. There must be definitions of these templates in some other file in the program,
i.e., templateBuild.cc in this program.
When the compiler sees an instantiation definition (as opposed to a declaration), it generatres code. Thus, the file templateBuild.o will contain the definitions
for compare instantiated with int and for the Blob<string>class. When we build the application, we must link templateBuild.o with the Application.o files.





