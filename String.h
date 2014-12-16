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
    
    //Default constructor
    String(void);

    //c-string constructor
    String(const char * s);
    
    //Copy consructor
    String(const String& str);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    
    //Destroys the string object.
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
     
    /* Returns a newly constructed string object with its value being the 
    concatenation of the characters in lhs followed by those of rhs.*/
     

    friend inline String operator+ (const String& lhs, const String& rhs);
    friend inline String operator+ (const String& lhs, char rhs);
    friend inline String operator+ (char rhs, const String& lhs);
    friend inline String operator+ (const char* lhs, const String& rhs);
    friend inline String operator+ (const String& lhs, const char* rhs);
    
    /* Returns a reference to the character at position pos in the string. */
    inline char& operator[] (size_t pos);
    inline const char& operator[] (size_t pos) const;

    /*Assigns a new value to the string, replacing its current contents.
    */
    inline String& operator= (const char* s);
    inline String& operator= (char c);

    /* Assigns a new value to the string, from a c-string */
    inline String& operator= (const String& str);


    // =======================================================================
    //                              Public Methods
    // =======================================================================
    
   /*Calculation of the size of the c-string, including '\0'*/
    unsigned int sizeCalculation(void);
    
    /*Returns the length of the string, in terms of bytes .*/
    size_t length() const;
    size_t size(void) const;
    
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

    /*Erase string contents and affects 1 to Size*/
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

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================



//Operator +
//Add  a char
inline String operator+ (const String& lhs, char rhs)
{
  int SizeRet=lhs.size()+2; //size() doesn't include '\0'
  char * DataRet=new char [SizeRet];
  memcpy(DataRet, lhs.Data, SizeRet);
  DataRet[SizeRet-2]=rhs;
  DataRet[SizeRet-1]='\0';
  String* ValRet=new String(DataRet);

  return *ValRet;
}

inline String operator+ (char rhs, const String& lhs)
{
  int SizeRet=lhs.size()+2;
  char * DataRet=new char [SizeRet];
  DataRet[0]=rhs;
  for(int i=1; i<SizeRet; i++)
  {
    DataRet[i]=lhs.Data[i-1];
  }
  DataRet[SizeRet-1]='\0';
  String* ValRet=new String(DataRet);
  
  return *ValRet;
}

inline String operator+ (const String& lhs, const String& rhs)
{
  int sum = lhs.size() + rhs.size()+1;
  
  char* NewData= new char[sum];
  int count=0;

  for(int i = 0 ; i<(lhs.size()); i++) {
    NewData[i]=lhs.Data[i];
    count=i;
  }

  for(int i=0; i<rhs.size(); i++){
    NewData[i+count+1]=rhs.Data[i];

  }

  NewData[(sum-1)]= '\0';
  String* ret = new String(NewData);

  return *ret;
}



inline String operator+ (const char* lhs, const String& rhs)
{
int r_sz=0;
  while(lhs[r_sz] != '\0') {
    r_sz++;
  }

  int sum3=rhs.size()+r_sz+1;

  char* NewData= new char[sum3];
  int count=0;

  for(int i = 0 ; i<r_sz; i++) {
    NewData[i]=lhs[i];
    count=i;
  }

  for(int i=0; i<(rhs.size()); i++){
    NewData[i+count+1]=rhs.Data[i];
  }
  
  NewData[(sum3-1)]='\0';
  String* ret = new String(NewData);

  return *ret;
}


inline String operator+ (const String& lhs, const char* rhs)
{
  int r_sz=0;
  while(rhs[r_sz] != '\0') {
    r_sz++;
  }

  int sum2=lhs.size()+r_sz+1;

  char* NewData= new char[sum2];
  int count=0;

  for(int i = 0 ; i<(lhs.size()); i++) {
    NewData[i]=lhs.Data[i];
    count=i;
  }

  for(int i=0; i<r_sz; i++){
    NewData[i+count+1]=rhs[i];
  }
  
  NewData[(sum2-1)]='\0';
  String* ret = new String(NewData);

  return *ret;
}



inline char& String::operator[] (size_t pos)
{
  size_t tmp;
  char ret;
  
  if(pos==Size){
    ret='\0';
    char& ref_1=ret;
    return ref_1;
  } else {
    ret= Data[pos];  
    char& ref_2=ret;
    return ref_2;
  }
}

inline const char& String::operator[] (size_t pos) const
{
  size_t tmp;
  char ret;
  
  if(pos==Size){
    ret='\0';
    const char& ref_1=ret;
    return ref_1;
  } else {
    ret= Data[pos];  
    const char& ref_2=ret;
    return ref_2;
  }
}

//Operator =

/*inline String& String::operator= (const char* s) {
  String*  ret = new String (s);
  String& ref_ret= *ret;
  return ref_ret;
}*/


inline String& String::operator= (char c)
{

  this->clear();
  this->Data[0] = c;
  //Size function return (Size-1)
  //So size of char is 2
  Size = 2; 
}

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
