/* strcat example */
//http://www.cplusplus.com/reference/cstring/strcat/
//char * strcat ( char * destination, const char * source );
//destination: Pointer to the destination array, which should contain a C string, and be large enough to contain the concatenated resulting string.
//Source: C string to be appended. This should not overlap destination.
//Return: destination
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[80];
  strcpy (str,"these ");
  strcat (str,"strings ");
  strcat (str,"are ");
  strcat (str,"concatenated.");
  puts (str);
  
//result: these strings are concatenated
  return 0;
}
