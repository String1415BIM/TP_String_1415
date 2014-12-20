//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <string.h>
#include <stdexcept>
#include <cstdio>
#include <cstdlib>

// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "String.h"

//############################################################################
//                                                                          
//                           Class String                           
//                                                                           
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

size_t String::MAX_SIZE = 100;

// ===========================================================================
//                                  Constructors
// ===========================================================================

//Creation of default constructor
String::String(void)
{
  Data = NULL;
  Size = 1;	//including '\0'
  Capacity= 1;	// including '\0'
}


unsigned int String::sizeCalculation(void)
{
  unsigned int i=0;
  while(Data[i]!='\0')
    {
      i++; 
    }
  return (i+1);
}

//Creation of constructor from a c-string
String::String(const char * s)
{
  //Size of s
  int Size_temp = 0;
  while( s[Size_temp] != '\0')
  {
    Size_temp ++;
  }
  Size= Size_temp +1;
  //Minimum capacity set at size value
  Capacity= Size;

  //Warning MAX_SIZE
  if (Capacity>MAX_SIZE)
  {
    printf("Please enter a string in argument which size is under %ld.\n", MAX_SIZE);
    exit(EXIT_FAILURE);
  }

  //Copy s into a String object
  Data = new char [Size];
  memcpy(Data,s,Capacity*sizeof(*Data));	
}


//Copy constructor
String::String(const String& str)
{
  Data= new char [str.Size];
  Size=str.Size;
  Capacity=str.Capacity;
  memcpy(Data,str.Data,Capacity*sizeof(*Data));
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
//Destroy the memory allocated for content
String::~String(void)
{
  if (Data!=NULL)
  {
    delete [] Data;
    Data = NULL;
  }
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

//Methods which looks like getters

  /*Getter on Capacity*/
size_t String::capacity(void) const
{
  return (Capacity-1)*sizeof(char);
}

  /*Getter on Data*/
char * String::c_str(void) const
{
    return Data;
}
  /*Getter on Max_Size*/
size_t String::max_size(void) const
{
  return MAX_SIZE;
}
  /*Getter on Size*/
size_t String::size(void) const
{
  return (Size-1);
}

size_t String::length() const
{
  return (Size-1);
}


void String::resize(size_t n) 
{
  //Warnings
  if (n+1>MAX_SIZE)
  {
     printf("The size in argument is greater than %ld (the MAX_SIZE allowed).\n",MAX_SIZE);
     exit(EXIT_FAILURE);
  }
  if (Size > n)
  {
    int i; 
    for (i=n;i<Size;i++)
    {
      Data[i] ='\0';
    }
    Size = n+1;
  }

  if (Size < n)
  {
    reserve(n+5);
    int i;
    for (i= Size-1; i<n; i++)
    {
      Data[i] = '\0';
    }
  }

}

void String::resize(size_t n, char c)
{
  //Warnings
  if (n+1>MAX_SIZE)
  {
     printf("The size in argument is greater than %ld (the MAX_SIZE allowed).\n",MAX_SIZE);
     exit(EXIT_FAILURE);
  }
  //else
  if (Size > n)
  {
    int i; 
    for (i=n;i<Size;i++)
    {
      Data[i] ='\0';
    }
    Size = n+1;
  }

  if (Size < n)
  {
    reserve(n+5);
    int i;
    for (i= Size-1; i<n; i++)
    {
      Data[i] = c;
    }
    Size = n+1;  
  }
  if (Size == n)
  {
    reserve(Size+2);
    Data[Size-1]=c;
    Size=Size+1;   
  }
}

char& String::at(size_t pos)
{
  //Warnings index is non correct
  if ((pos >= Size)||(pos<0))
  {
    throw std::out_of_range("Index value should be positive and under the string length.\n");
  }
  static char s = '\0';
  s = Data[pos];
  return s; 
}


const char& String::at(size_t pos) const
{
  //Warnings
  if (pos >= Size || pos<0)
  {
    throw std::out_of_range("Index value should be positive and under the string length.\n");
  }
  static char s = '\0';
  s = Data[pos];
  return s; 
}


//Methods which looks like setters
/*Setter on Capacity*/
void String::reserve(size_t n)
{
  //Warnings
  if (n+1>MAX_SIZE)
  {
    printf("The size reserved is greater than %ld (the MAX_SIZE defined).\n", MAX_SIZE);
    exit(EXIT_FAILURE);
  }
  if(Capacity<n) 
  {
    Capacity=n+1;
  }
}


// If Size=1 -> String is empty -> bool=1 // else bool=0
bool String::empty(void) const
{
  bool ret = 0;
  if (Size==1){
    ret = 1;
  }
  return ret;
}

void String::clear(void)
{
  int i=0;
  while(at(i)!='\0')
  {
    Data[i]='\0';
    i++;
  }
  Size=1;
}


