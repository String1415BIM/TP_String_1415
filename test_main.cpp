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
#include <iostream>

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
  String *  test = new String();


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

  //creating default string
  String* def_string = new String();




  //test MAX_SIZE

  printf("Max size test \n");
  printf("max_size=%d \n",test->max_size());

  //printf("max_size=%d \n",test_cstring->max_size());


  
  //test resize
  printf("Resize test \n");
  test_cstring->resize (10);
  printf("resize: %s \n",test_cstring->c_str());

  test_cstring->resize (8, 'a');
  printf("resize: %s \n",test_cstring->c_str());
  
  test_cstring->resize (5, 'a');
  printf("resize: %s \n",test_cstring->c_str());

  test_cstring->resize (10, 'a');
  printf("resize: %s \n",test_cstring->c_str());

  //test at
  printf("At index asked, char= %c \n",test_cstring->at (5));


  //Test on '= operator' on a char

  
  /*mot2="Bonjour"; //test avec le operateur=string
  mot2 = 'c';
  printf("%c\nlength: %d\n",mot2[0],mot2.length());*/



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
  printf("booleen : %d \n",def_string->empty());



  //Test on clear method
  char word[]="Link list";
  String* testo=new String(word);
  printf("%s, size=%d\n", testo->c_str(), testo->size());
  testo->clear();
  printf("%s, size=%d\n", testo->c_str(), testo->size());


  //Test on operators of Student 1
  String test_operator1=String("Team Rocket");
  printf("\n %s (%d) \n", test_operator1.c_str(), test_operator1.size());
  String test_operator2= String ();
  test_operator2 = test_operator1 + '!';
  test_operator2 = '?' + test_operator1;
  printf("%s (%d, capacity=%d)\n \n", test_operator2.c_str(), test_operator2.size(), test_operator2.capacity());


  //Test on operators of Student 2
  //operateur "="
  printf("Test Noelie operator \n");
  String test_1=String("TeamRocket");
  printf("%s (%d) + !\n", test_1.c_str(), test_1.size());
  char a = 'a';
  test_1 = a;
  printf("%s (%d) + !\n", test_1.c_str(), test_1.size());
  //operateur "+"
  String testo_1=String("TeamRocket2");
  printf("%s (%d) + !\n", testo_1.c_str(), testo_1.size());
  String string2= String ();
  string2 =  testo_1+ "Yes";
  printf("%s (%d) + !\n", string2.c_str(), string2.size());


  printf("Fin test Noelie operator \n");

  

  //Test on operators of Student 3 


  String test_op_1=String("test operat");
  String test_op_2=String("eur");
  char* char_test = " foo";
    
    // Test of operator +(string)
  
  String returned_Str= test_op_1 + test_op_2; 
  printf("%s \n", returned_Str.c_str() );

  String returned_chr = returned_Str + char_test;
  printf("%s \n", returned_chr.c_str() );

  String returned_chr_2= char_test+test_op_1;
  printf("%s \n", returned_chr_2.c_str() );
    // Test of operator []
  for (int i=0; i<=test_operator1.size(); i++) {
    printf("%c\n", test_operator1[i] );
  }

  printf("Character null : %c\n", test_operator1[12] );

    
 
    // Test of operator =(char*)
  String myString1=String("Bonjour");
  printf("%s \n", myString1.c_str() );


  char* toPut = "Hello";
  printf("%s \n", toPut );
  myString1= toPut;

  printf("%s\n", myString1.c_str() );

//  printf("Finalement : %s\n", myString1.c_str() );



  return 0;

}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

