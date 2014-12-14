//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __STRING_H__
#define __STRING_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <string.h>



// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================






class String
{
  public:
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    
    //default constructor
    String(void);

    //c-string constructor
    String(const char * s);
    
    //copy consructor
    String(const String& str);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~String(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline unsigned int getSize(void) const;
    inline char * getString(void) const;
    inline char getLetter(int pos) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================
   
    /* Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
     */

    friend inline String operator+ (const String& lhs, const String& rhs);
    inline String operator+ (char rhs);
    friend inline String operator+ (const char* lhs, const String& rhs);

    inline char& operator[] (size_t pos);
    inline String& operator= (const char* s);

    /* Assigns a new value to a string, from a c-string (str)*/
    inline String& operator= (const String& str);

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    
    
    /* Returns the maximum length the string can reach.
    */
    size_t max_size(void) const;


    /*Resizes the string to a length of n characters.
    */
    void resize (size_t n);
    void resize (size_t n, char c);


    /*Returns a reference to the character at position pos in the string.
    */
    char& at (size_t pos);
    const char& at (size_t pos) const;


    /* Returns the size of the storage space currently allocated for the string, expressed in terms of bytes.
     */
    size_t capacity (void) const;

    /* Returns whether the string is empty (i.e. whether its length is 0). True means empty
     */
    bool empty (void) const;

    /*Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
      If n is greater than the current string capacity, the function causes the container to increase its capacity to n characters 
      In all other cases, it is taken as a non-binding request to shrink the string capacity:
      the container implementation is free to optimize otherwise and leave the string with a capacity greater than n.
    */
    void reserve (size_t n = 0);

    /* Returns a pointer on a c-string. It is a getter on string variable*/
    char * c_str(void) const;

    /*Calculation of the size of the c-string*/
    unsigned int sizeCalculation(void);

    /*Returns the size of string*/
    size_t size(void) const;
    
    size_t length() const;


 
    String& operator=(char c);
    String operator+ (const char* rhs);

    /* Erase string contents and affects 0 to size*/
    void clear(void);
    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected:

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================



    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================


    static unsigned int MAX_SIZE;
    unsigned int Capacity;
    char * Data;
    unsigned int Size;
       
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline unsigned int String::getSize(void) const
{
  return Size;
}

inline char * String::getString(void) const
{
  return Data;
}

inline char String::getLetter(int pos) const
{
  return Data[pos];
}
// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================


//Operator +
//Add  a char
inline String String::operator+ (char rhs)
{
  //If Capacity=Size, we had to up Capacity
  if(this->Size+1>Capacity) 
  {
    reserve(Size+10);
  }
  
  this->Size=Size+1;
  this->Data[Size-2]=rhs;
  this->Data[Size-1]='\0';

  return *this;
}

inline String operator+ (const String& lhs, const String& rhs)
{
  int sum = lhs.size() + rhs.size();
  String ret = lhs;
  int rsz =rhs.size();
  char* tmp = new char [rsz+1];
  tmp= rhs.Data;
  ret.resize(sum);
  for(int i = (lhs.size()-1) ; i<sum+1; i++) {
    ret.Data[i]=tmp[i];
  }
  return ret;
}

inline char& String::operator[] (size_t pos)
{
  size_t tmp;
  char ret;
  
  if(pos==Size){
    ret='\0';
    char& def_ref=ret;
    return def_ref;
  } else {
    ret= Data[pos];
  }
  char& ref=ret;
  return ref;
}

//Operator =
inline String& String::operator= (const char* s)
{
  delete[] Data;
  int NewSize=0;

  while(s[NewSize] != '\0'){
    NewSize++;
  }
  this->Size=NewSize;
  this->Capacity=NewSize;
  Data= new char [NewSize];
  memcpy(this->Data, s, NewSize*sizeof(char) );
  return *this;
}

inline String& String::operator= (const String& str)
{
  delete [] Data; //if Data is not empty

  Data=new char [str.Capacity];
  Size=str.Size;
  Capacity=str.Capacity;
  memcpy(Data, str.Data, str.Size);

  return *this;
}

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __STRING_H__
