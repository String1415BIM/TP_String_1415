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
#include <string.h>
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


  //test du c-string constructor
  char mot[8] ="Bonjour";
  String* test_cstring = new String(mot);
  printf("size=%d, word= %s\n", test_cstring->getSize(), test_cstring->getString());


  //Test for the copy constructor
  String model=String();
  String test_copy=String(model);

  printf("%s\n",test_cstring->c_str()); 
  printf("%d\n",test_cstring->size());


  //Test on reserve, capacity, empty methods
  printf("capacite 1 : %d \n",test_cstring->capacity());
  test_cstring->reserve(10);
  printf("capacite 2 : %d \n",test_cstring->capacity());

  test_cstring->reserve();
  printf("size : %d \n", test_cstring->size());
  printf("booleen : %d \n",test_cstring->empty());

  /* //Test on clear method
  char word[]="Link list";
  String testo=String(word);
  printf("%s, size=%d\n", testo.c_str(), testo.Size());
  testo.clear();
  printf("%s, size=%d\n", testo.c_str(), testo.Size());
  */
  return 0;

}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

