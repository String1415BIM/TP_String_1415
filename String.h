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
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================
   
    /* Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
     */

    friend inline String operator+ (const String& lhs, const String& rhs);
    friend inline String operator+ (const String& lhs, char rhs);
    friend inline String operator+ (char lhs, const String& rhs);

    /* Returns a new object string which contains rhs and lhs at the end*/
    friend inline String operator+ (const char* lhs, const String& rhs);

    /* Assigns a new value to a string, from a c-string*/

    //friend inline String& operator=(const String& str);
   
  //String& operator=( const String& other );

    inline String& operator=(const String& str);


    //String& operator=( const String& other );


    // =======================================================================
    //                              Public Methods
    // =======================================================================
    
    
    /* Returns the maximum length the string can reach.
    */
    size_t max_size(void) const;


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
    unsigned int size(void) const;

 

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
// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

/*inline string operator+ (const string& lhs, char rhs)
{
  int NewSize = lhs.size()+1;
  String ret = lhs;
  ret.resize(NewSize);
  ret.Data[NewSize]= rhs;
  return ret;
}

inline String operator+ (char lhs, const string& rhs)

{
  int NewSize = rhs.size()+1;
  String ret = lhs;
  ret.resize(NewSize);
  ret.Data[NewSize]= rhs;
  return ret;
  }*/

inline String operator+ (const String& lhs, const String& rhs)
{
  int sum = lhs.size() + rhs.size();
  String ret = lhs;
  int rsz =rhs.size();
  char* tmp = new char [rsz];
  tmp= rhs.Data;
  // ret.resize(sum);
  for(int i = lhs.size() ; i<sum; i++) {
    ret.Data[i]=tmp[i];
  }
  return ret;
}



// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __STRING_H__

