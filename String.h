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
    String(char * stringToAppend);
    
    //copy consructor
    String(const String& str);
    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~String(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline unsigned int GetSize(void) const;
    inline char * GetString(void) const;
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    /* Returns the size of the storage space currently allocated for the string, expressed in terms of bytes.
     */
    size_t Capacity (void) const;

    /* Returns whether the string is empty (i.e. whether its length is 0). True means empty
     */
    bool Empty (void) const;

    /*Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
      If n is greater than the current string capacity, the function causes the container to increase its capacity to n characters 
      In all other cases, it is taken as a non-binding request to shrink the string capacity:
      the container implementation is free to optimize otherwise and leave the string with a capacity greater than n.
    */
    void Reserve (size_t n = 0);

    /* Returns a pointer on a c-string. It is a getter on string variable*/
    char * c_str(void) const;

    /*Calculation of the size of the c-string*/
    unsigned int SizeCalculation(void);

    /*Returns the size of string*/
    unsigned int Size(void) const;

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
    unsigned int capacity;
    char * string;
    unsigned int size;
       
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline unsigned int String::GetSize(void) const
{
    return size;
}

inline char * String::GetString(void) const
{
    return string;
}
// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __STRING_H__

