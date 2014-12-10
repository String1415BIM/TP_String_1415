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
  String  test =String();

  char mot[8] ="Bonjour";
  String test_cstring =String(mot);
  printf("size=%d, word= %s\n", test_cstring.GetSize(), test_cstring.GetString());

  //Test for the copy constructor
  String model=String();
  String test_copy=String(model);

  //Test on c_str & size methods
  printf("%s\n",test_cstring.c_str()); 
  printf("%d\n",test_cstring.Size());

  printf("%d \n",test_cstring.Capacity());
  test_cstring.Reserve(10);
  printf("%d \n",test_cstring.Capacity());

  //Test on clear method
  char word[]="Link list";
  String testo=String(word);
  printf("%s, size=%d\n", testo.c_str(), testo.Size());
  testo.clear();
  printf("%s, size=%d\n", testo.c_str(), testo.Size());



    return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

