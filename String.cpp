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
  string = NULL;
  size = 0;	
  capacity= 0;	
}


//Constructor from a c-string
String::String(const char * s)
{
  string = new char [capacity];
  memcpy(string,s,capacity*sizeof(*string));	
  size =SizeCalculation();
  capacity= 0;
}

//Copy constructor
String::String(const String& str)
{
  string=str.string;
  size=str.size;
  capacity=str.capacity;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
String::~String(void)
{
  delete string;
  string = NULL;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
size_t String:: Capacity (void) const
{
  return capacity*sizeof(char);
}

void String :: Reserve (size_t n)
{
  if(capacity<n) {
    capacity=n;
  }
}


char * String::c_str(void) const
{
    return string;
}



bool String :: Empty (void) const
{
  bool ret = 0;
  if (size==0){
    ret = 1;
  }
  return ret;
}

unsigned int String::SizeCalculation(void)
{
	unsigned int i=0;
	while(string[i]!='\0')
    {
      i++; 
    }
    return (i+1);
}

unsigned int String::Size(void) const
{
	return (size-1);
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
