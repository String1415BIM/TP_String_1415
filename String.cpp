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
  Size = 1;	//including '\0'
  Capacity= 0;	
}


//Constructor from a c-string
String::String(const char * s)
{
  int Size_temp = 0;
  while( s[Size_temp] != '\0')
  {
    Size_temp ++;
  }
  Size= Size_temp +1;
  Capacity= Size;
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
  delete [] Data;
  Data = NULL;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================



size_t String::String::max_size(void) const
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
    Size = n+1;
  }

}


void String::String::resize (size_t n, char c)
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



bool String ::empty (void) const
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

size_t String::size(void) const
{
	return (Size-1);
}

void String::clear(void)
{
  Data[0]='\0';
  Size=1;
}

String operator+ (const String& lhs, char rhs)
{
  String ret= String();
  ret.Size=lhs.size()+1;
  ret.reserve(ret.Size);
  //memcpy(ret.Data, lhs.Data, lhs.Size*sizeof(ret.Data));
  //ret.resize(ret.size()+2, rhs);
  return ret;
}

/*String& operator=(const String& str)
{
  static String rtn_value=String(str);
  rtn_value.resize(str.size());
  rtn_value.Data=str.c_str();
  printf("%s, %d\n", rtn_value.c_str(), rtn_value.size());
  return rtn_value;
} */  

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
