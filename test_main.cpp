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
  
  String *  test = new String();

  //-------------------------------------------------------------------------------
  //test C-STRING CONSTRUCTOR
  //-------------------------------------------------------------------------------
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



  //-------------------------------------------------------------------------------
  //test MAX_SIZE
  //-------------------------------------------------------------------------------
  printf("Max size test \n");
  printf("max_size=%d \n",test_cstring->max_size());

  //-------------------------------------------------------------------------------
  //test RESIZE
  //-------------------------------------------------------------------------------

  printf("Resize test \n");
  test_cstring->resize (10);
  printf("resize: %s \n",test_cstring->c_str());

  test_cstring->resize (8, 'a');
  printf("resize: %s \n",test_cstring->c_str());
  
  test_cstring->resize (5, 'a');
  printf("resize: %s \n",test_cstring->c_str());

  test_cstring->resize (10, 'a');
  printf("resize: %s \n",test_cstring->c_str());


  //-------------------------------------------------------------------------------
  //test AT
  //-------------------------------------------------------------------------------
  
  printf("At index asked, char= %c \n\n",test_cstring->at (5));


  //-------------------------------------------------------------------------------
  //test CAPACITY and  RESERVE
  //-------------------------------------------------------------------------------
  printf("Capacity \n\n");

  String* test_reserve = new String();
  
  test_reserve->reserve();
  printf("Default capacity : %d \n",test_reserve->capacity());
  
  printf("capacity 1 : %d \n\n",test_cstring->capacity());
  printf("Reserve 20 \n");
  test_cstring->reserve(20);
  printf("capacite 2 : %d \n\n",test_cstring->capacity());
  
  //-------------------------------------------------------------------------------
  //test EMPTY
  //-------------------------------------------------------------------------------
  printf("Empty \n\n");

  printf("booleen of fulled string : %d \n",test_cstring->empty());
  printf("boolean of empty string : %d \n",test_reserve->empty());



  //Test on clear method
  char word[]="Link list";
  String* testo=new String(word);
  printf("%s, size=%d\n", testo->c_str(), testo->size());
  testo->clear();
  printf("%s, size=%d\n", testo->c_str(), testo->size());



  //-------------------------------------------------------------------------------
  //test OPERATOR
  //-------------------------------------------------------------------------------



  //-------------------------------------------------------------------------------
  //operator "="
  //-------------------------------------------------------------------------------
  
  //   "=" operator with char type 
  printf("= operator with char type \n");
  String test_1=String("TeamRocket");
  printf("%s (%d) + !\n", test_1.c_str(), test_1.size());
  char a = 'a';
  test_1 = a;
  printf("%s (%d) + !\n", test_1.c_str(), test_1.size());


  //Test on operators of Student 1
  String test_operator1=String("Team Rocket");
  printf("%s (%d) + !\n", test_operator1.c_str(), test_operator1.size());
  String test_operator2= String ();
  printf("%s (%d)\n", test_operator2.c_str(), test_operator2.size());


  // "=" operator with char* type
  
  String myString1=String("Bonjour");
  printf("%s will become ", myString1.c_str() );
  char* toPut = "Hello";
  printf("%s. ", toPut );
  myString1= toPut;
  printf("Finally : %s\n", myString1.c_str() );


  //-------------------------------------------------------------------------------
  //operator "+"
  //-------------------------------------------------------------------------------
  
  
  // "+" operator with char* type

  String testo_1=String("TeamRocket2");
  printf("%s (%d) + !\n", testo_1.c_str(), testo_1.size());
  String string2= String ();
  string2 =  testo_1+ "Yes";
  printf("%s (%d) + !\n", string2.c_str(), string2.size());


  // "+" operator with string type
  String test_op_1 = "Hel";
  String test_op_2 = "lo";
  printf("test_op_1:  %s + test_op_2: %s = ", test_op_1.c_str(), test_op_2.c_str() );
  String returned_Str= test_op_1 + test_op_2; 
  printf("%s \n", returned_Str.c_str() );
 

  //-------------------------------------------------------------------------------
  //operator "[]"
  //-------------------------------------------------------------------------------
  
  for (int i=0; i<=returned_Str.size(); i++) {
    printf("%c\n", returned_Str[i] );
  }
  printf("Character null : %c\n", test_operator1[12] );





  //student1
  test_operator2 = test_operator1 + '!';
  test_operator2 = '?' + test_operator1;
  printf("%s (%d, capacity=%d)\n", test_operator2.c_str(), test_operator2.size(), test_operator2.capacity());


  return 0;

}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================




