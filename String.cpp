//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "String.h"
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <stdexcept>




//############################################################################
//                                                                          
//                           Class String                           
//                                                                           
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================

//Creation of default constructor
String::String(void)
{
  Data = NULL;
  Size = 1;	//including '\0'
  Capacity= 0;	
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



size_t String::max_size(void) const
{
  return MAX_SIZE;
}


void String::resize (size_t n) //cas ou Size=n
{
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

char& String::at (size_t pos)
{
  static char s = '\0';
  s = Data[pos];
  //If index is non correct
  if ((pos >= Size)||(pos<0))
  {
    throw std::out_of_range("Index asked is more than the string length.\n");
  }
  return s; 
}


const char& String::at (size_t pos) const
{
  static char s = '\0';
  unsigned int i=0;
  while(Data[i]!='\0')
  {
    if (pos == i)
    {
     s = Data[i];
    }
    i++;
  }
  if (pos >= Size)
  {
    throw std::out_of_range("Index value asked is more than the string length.\n");
  }
  return s; 
}



size_t String::capacity (void) const
{
  return (Capacity-1)*sizeof(char);
}

void String::reserve (size_t n)
{
  if(Capacity<n) 
  {
    Capacity=n+1;
  }
}


char * String::c_str(void) const
{
    return Data;
}


bool String::empty (void) const

{
  bool ret = 0;
  if (Size==1){
    ret = 1;
  }
  return ret;
}


size_t String::size(void) const
{
	return (Size-1);
}

size_t String::length() const
{
  return (Size-1);
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





// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
