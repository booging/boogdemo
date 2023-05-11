#include <string> // This include allows usage of std::string
void Demo_DataTypes()
{
    /* ------------ Introduction ------------*/
    // In 64-bit C++ programming, there are 5 basic data types:
    // bool, char, short, int, float, double, __int64 (aka long long)

    /* ------------ Memory sizes ------------*/
    // Each one of these data types takes up a specific amount of room (bytes) in memory:
    // bool - 1 byte (stores 'true' or 'false')
    // char - 1 byte (stores 1 character, such as 'A' or 'B' or any value from 0-255)
    // short - 2 bytes
    // int - 4 bytes
    // float - 4 bytes
    // double - 8 bytes (double-precision float)
    // __int64 - 8 bytes (basically an int with a much larger numeric range)
    // These sizes are very important to learn if you want to edit process memory
    
    /* ------------ Unsigned/signed ------------*/
    // integral types (char, short, int and __int64) can have the 'unsigned' specifier (i.e "unsigned __int64" or "unsigned int")
    // unsigned types can not have negative values, but can have twice as high positive values
    // signed types (values that are not unsigned) can have negative values, but they can only be half as big as their unsigned counterparts
    // values that do not have the 'unsigned' specifier are signed by default

    /* ------------ Size constraints ------------*/
    // note that 1 byte can have a maximum value of 0xFF in hexadecimal, meaning that if a type has for example
    // 2 bytes (unsigned short) then its maximum value will be 0xFFFF, or 65535 in decimal. 
    // If it is signed, then the maximum value will be 32767 (half of 65535) and the minimum value will be -32767.
    // For booleans, any non-zero value means 'true' and a value of zero means 'false'

    /* ------------ Strings ------------*/
    // Strings are actually not a basic data type but are rather arrays of characters, or 'char's.
    // These strings are allocated in memory when the program is compiled and are generally stored as "const char*"
    // There is also an std::string type, which wraps a character array and makes it easier to use.

    /* ------------ Initialization ------------*/
    // Initialization looks like this: <DataType> <VariableName> = <Value>
    bool Boolean					= false;
    char Character					= 'A';			// Single character, can also be initialized with an integral value
    char IntegCharacter				= char(123);
    unsigned char UCharacter		= 'B';
    short ShortInteger				= -1234;
    unsigned short UShortInteger	= 1234;
    int Integer						= -12345678;
    unsigned int UInteger			= 12345678;
    float FloatingPointNumber		= 1.2f;			// Note the decimal expression followed by an 'f' character
    double DoublePrecisionFloat		= 2.4;			// Note the decimal expression WITHOUT the 'f' character, this indicates a double-precision floating point value
    __int64 LongInteger				= -1234567890;
    unsigned __int64 ULongInteger	= 123456789;
    const char* CStyleString		= "Hello";
    std::string StandardString		= "Hello";
    std::string OtherStdString		= std::string(CStyleString); // Constructs an std::string from an existing const char*

    /* ------------ Type alisaing (typedefs) ------------*/
    // Aside from this, there may be aliased types - types that have a different name but are the same as one of these basic data types
    // Aliased types are created using a 'typedef' statement, like so:
    typedef unsigned int uint32_t; // This uint32_t type behaves the exact same way as "unsigned int", including initialization and size constraints
    uint32_t UInteger2 = 12345678;
    // Typically when using any standard headers, these aliased types will exist:
    // uint8_t = unsigned char
    // int8_t = char
    // uint16_t = unsigned short
    // int16_t = short
    // uint32_t = unsigned int
    // int32_t = int
    // uint64_t = unsigned __int64
    // int64_t = __int64
    // These are not that important to learn, but it does look better when you use the unsigned aliases instead of writing the full type name.
}