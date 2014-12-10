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
//                                                                           #
//                           Class Template_class                            #
//                                                                           #
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

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
