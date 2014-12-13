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
  String *  test =new String();


  //test c-string constructor
  char mot[8] ="Bonjour";
  String* test_cstring = new String(mot);
  printf("size=%d, word= %s\n", test_cstring->size(), test_cstring->c_str());


  //Test for the copy constructor
  printf("Copy constructor test \n");
  String model=String(mot);
  String test_copy=String(model);
  printf("size=%d, word= %s\n", test_copy.size(), test_copy.c_str());

  printf("%s\n",test_cstring->c_str()); 
  printf("%d\n",test_cstring->size());




  //test MAX_SIZE
  printf("Max size test \n");
  printf("max_size=%d \n",test->max_size());

  
  //test resize
  printf("Resize test \n");
  test_cstring->resize (10);
  printf("resize: %s \n",test_cstring->c_str());
  
  test_cstring->resize (5, 'a');
  printf("resize: %s \n",test_cstring->c_str());

  test_cstring->resize (10, 'a');
  printf("resize: %s \n",test_cstring->c_str());



  //Test on reserve, capacity, empty methods
  printf("Capacity test \n");
  printf("capacite 1 : %d \n",test_cstring->capacity());
  
  printf("Reserve test \n");
  test_cstring->reserve(20);
  printf("capacite 2 : %d \n",test_cstring->capacity());
  test_cstring->reserve();
  printf("capacite par defaut : %d \n",test_cstring->capacity());
  
  printf("size : %d \n", test_cstring->size());


  printf("Empty test \n");
  printf("booleen : %d \n",test_cstring->empty());

  //Test on clear method
  char word[]="Link list";
  String* testo=new String(word);
  printf("%s, size=%d\n", testo->c_str(), testo->size());
  testo->clear();
  printf("%s, size=%d\n", testo->c_str(), testo->size());
  
    return 0;

}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

