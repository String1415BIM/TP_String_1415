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
  
  //Test for constructor from a c-string
  //Includes a test for c_str() & size()
  char mot[8] ="Bonjour";
  String* test_cstring = new String(mot);
  printf("C-string constructor, size  and c_str tests\n"); 
  printf("size=%d, word= %s\n \n ", test_cstring->size(), test_cstring->c_str());

  //Test for the copy constructor
  printf("Copy constructor test \n");
  String model=String(mot);
  String test_copy=String(model);
  printf( "%s  (%d),\n\n", test_copy.c_str(), test_copy.size());

  //-------------------------------------------------------------------------------
  //test MAX_SIZE
  //-------------------------------------------------------------------------------
  printf("Max size test \n");
  printf("max_size=%d \n\n",test_cstring->max_size());

  //-------------------------------------------------------------------------------
  //test Size & C_STR
  //-------------------------------------------------------------------------------

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
  printf("resize: %s \n\n",test_cstring->c_str());


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


  printf("Empty test \n");

  printf("booleen of fulled string : %d \n",test_cstring->empty());
  printf("boolean of empty string : %d \n\n",test_reserve->empty());




  //Test on clear method
  String* testo=new String("clean that");
  testo->clear();
  printf("After clear(): %s, size=%d\n\n", testo->c_str(), testo->size());



  //-------------------------------------------------------------------------------
  //test OPERATOR
  //-------------------------------------------------------------------------------



  //-------------------------------------------------------------------------------
  //operator "="
  //-------------------------------------------------------------------------------

  printf("----------------\n Operator = test\n\n");
  //   "=" operator with char type 
  printf("= operator with char type \n");
  String test_1=String("TeamRocket");
  printf("%s (%d) + !\n", test_1.c_str(), test_1.size());
  char a = 'a';
  test_1 = a;
  printf("%s (%d) + !\n\n", test_1.c_str(), test_1.size());


  //"=" operator with String type
  String test_operator1=String("Team Rocket");
  String test_operator2= String ();
  test_operator2=test_operator1;
  printf("= Operator from char: %s (%d)\n\n", test_operator2.c_str(), test_operator2.size());


  // "=" operator with char* type
  String myString1=String("Bonjour");
  printf("(String)  %s will become ", myString1.c_str() );
  char* toPut = "Hello";
  printf("(char*)  %s (5) .\n ", toPut );
  myString1= toPut;
  printf("test of =(char*) operator \n ");
  printf("Finally : %s (%d)  \n\n", myString1.c_str(), myString1.size() );

  //-------------------------------------------------------------------------------
  //operator "+"
  //-------------------------------------------------------------------------------
  
  printf("----------------\n Operator + test\n\n");
  // "+" operator with char* type

  String testo_1=String("TeamRocket2");
  printf("%s (%d) + !\n", testo_1.c_str(), testo_1.size());
  String string2= String ();
  string2 =  testo_1+ "Yes";
  printf("%s (%d) + !\n\n", string2.c_str(), string2.size());


  // "+" operator with string type
  String test_op_1 = "Hel";
  String test_op_2 = "lo";
  printf("(string) test_op_1:  %s (%d) + (string) test_op_2: %s (%d) = ", test_op_1.c_str(),test_op_1.size(), test_op_2.c_str(), test_op_2.size() );
  String returned_Str= test_op_1 + test_op_2; 
  printf("%s (%d)\n\n", returned_Str.c_str(), returned_Str.size() );

  // "+" operator with char type
  printf("Add a char to a String\n");
  test_operator2.clear();
  test_operator2 = test_operator1 + '!';
  test_operator2 = '?' + test_operator1;
  printf("%s (%d, capacity=%d)\n", test_operator2.c_str(), test_operator2.size(), test_operator2.capacity());
  test_operator2.clear();
  test_operator2 = test_operator1 +'!';
  printf("%s (%d, capacity=%d)\n\n", test_operator2.c_str(), test_operator2.size(), test_operator2.capacity());


  //-------------------------------------------------------------------------------
  //operator "[]"
  //-------------------------------------------------------------------------------
  printf("----------------\n Operator [] test\n\n");
  for (int i=0; i<=returned_Str.size(); i++) {
    printf("[%d]= '%c'\n", i,returned_Str[i] );
  }
  printf("Character null [12] : '%c'\n", test_operator1[12] );



  //End of tests with tes_cstring
  //delete test_cstring;



  return 0;

}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================




