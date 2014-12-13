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
  String model=String(mot);
  String test_copy=String(model);
  printf("size=%d, word= %s\n", test_copy.size(), test_copy.c_str());

  printf("%s\n",test_cstring->c_str()); 
  printf("%d\n",test_cstring->size());




  //test MAX_SIZE
  printf("max_size=%d \n",test_cstring->max_size());

  
  //test resize
  test_cstring->resize (10);
  printf("resize: %s \n",test_cstring->c_str());
  
  test_cstring->resize (5, 'a');
  printf("resize: %s \n",test_cstring->c_str());

  test_cstring->resize (10, 'a');
  printf("resize: %s \n",test_cstring->c_str());

  //test at
  printf("At index asked, char= %c \n",test_cstring->at (5));


  //Test on reserve, capacity, empty methods
  printf("capacite 1 : %d \n",test_cstring->capacity());
  test_cstring->reserve(10);
  printf("capacite 2 : %d \n",test_cstring->capacity());

  test_cstring->reserve();
  printf("size : %d \n", test_cstring->size());
  printf("booleen : %d \n",test_cstring->empty());

  //Test on clear method
  char word[]="Link list";
  String* testo=new String(word);
  printf("%s, size=%d\n", testo->c_str(), testo->size());
  testo->clear();
  printf("%s, size=%d\n", testo->c_str(), testo->size());


  //Test on operators of Student 1
  String test_operator1=String("Team Rocket");
  char letter= 's';
  /*printf("\n\nOperator=\n %s\n", test_operator1.c_str());
  String test_operator2=String();
  //test_operator2 = test_operator1;
  printf("%s, %d\n", test_operator2.c_str(), test_operator2.size());
  */
  printf("%s (%d) + %c\n", test_operator1.c_str(), test_operator1.size(), letter);
  String test_operator2=String();
  test_operator2= test_operator1 + letter;
  printf("%s %d, \n",test_operator2.c_str(), test_operator2.size()); /*test_operator2.c_str());*/

  return 0;

}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

