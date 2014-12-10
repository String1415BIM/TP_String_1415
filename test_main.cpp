//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <stdio.h>
#include "String.h"
#include <stdbool.h>

// ===========================================================================
//                               Static Attributes
// ===========================================================================


unsigned int String::MAX_SIZE = 100;
// ===========================================================================
//                             Include Project Files
// ===========================================================================



// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================








// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  printf("Hello World !\n");
  String * test = new String();

  char mot[8] ="Bonjour";
  String* test_cstring = new String(mot);

  //Test for the copy constructor
  String model=String();
  String test_copy=String(model);

  //Test on c_str & size methods
  printf("%s\n",test_cstring->c_str()); 
  printf("%d\n",test_cstring->Size());

  test_cstring->Reserve(10);

  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

