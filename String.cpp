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
#include <string.h>




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

//Default constructor
String::String(void)
{
  Data = NULL;
  Size = 0;	
  Capacity= 0;	
}


//Constructor from a c-string
String::String(const char * s)
{
  Data = new char[Capacity];
  printf("%d\n", capacity);
  memcpy(Data,s,sizeof(*Data));
  printf("Data=%s\n", Data);
  Size =sizeCalculation();
  Capacity= 0;

}

//Copy constructor
String::String(const String& str)
{
  Data=str.Data;
  Size=str.Size;
  Capacity=str.Capacity;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
String::~String(void)
{
  delete [] Data;
  Data = NULL;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
size_t String:: capacity (void) const
{
  return Capacity*sizeof(char);
}

void String :: reserve (size_t n)
{
  if(Capacity<n) {
    Capacity=n;
  }
}


char * String::c_str(void) const
{
    return Data;
}



bool String :: empty (void) const
{
  bool ret = 0;
  if (Size==0){
    ret = 1;
  }
  return ret;
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

unsigned int String::size(void) const
{
	return (Size-1);
}

void String::clear(void)
{
  Data[0]='\0';
  Size=1;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
