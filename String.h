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
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    String(void);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~String(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================

    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Template_class(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    /*Template_class(const Template_class &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/


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

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __SRING_H__

