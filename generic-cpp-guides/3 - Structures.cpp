/* ------------ Introduction ------------*/
// Structures can be seen as arrangements of various data types (sometimes even other structures)
// These structures are also considered data types.
// Structures can also contain functions (but this is more common with classes)

/* ------------ Memory sizes ------------*/
// The size of a structure in memory is determined by the sum of its member types' sizes

/* ------------ Examples ------------*/
struct ExampleStruct1
{
    unsigned int UInteger;
    int SInteger;
    bool BoolValue;
};
// In this structure, the size in memory is 4 bytes + 4 bytes + 1 byte (see guide #1) - meaning the full size of the structure is 9 bytes.
struct ExampleStruct2
{
    unsigned int UInteger;
    int SInteger;
    bool BoolValue;
    // This is a constructor function. It helps you initialize structures.
    ExampleStruct2(unsigned int uint, int sint, bool boolval)
    {
        UInteger = uint;
        SInteger = sint;
        BoolValue = boolval;
    }
};


/* ------------ Using structures ------------*/
void Demo_Structures()
{
    // Initialization of a structure without a constructor can look like this:
    ExampleStruct1 Struct1{0, 1, true};
    // The members of the structure are initialized in the order they were written when defining the structure

    // Initialization of a structure WITH a constructor looks like this:
    ExampleStruct2 Struct2(0, 1, true); // Here we are calling the constructor of ExampleStruct2, which automatically sets
                                        // the values of the data members for us. Here the order of initialization depends
                                        // on the code in the constructor.

    // To access structure members, simply append the variable name with ".<MemberName>". Example:
    bool Struct1Boolean = Struct1.BoolValue;
    bool Struct2Boolean = Struct2.BoolValue;
}