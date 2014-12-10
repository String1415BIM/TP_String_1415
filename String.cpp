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
String::String(char * stringToAppend)
{
  string = stringToAppend;
  size = 0;	
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
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
