#include <iostream> // for std::cout
/* ------------ Introduction ------------*/
// Functions are repeatable sequences of code that make up a program.
// They can return (output) values of any type and can take any combination of parameters (input)
// The format of any normal function is: <ReturnType> <Name>(<ParameterType> ParameterName, ...)
// A function that does not return a value uses 'void' as its ReturnType.
// A function which does return a value MUST contain a 'return' statement to avoid undefined behaviour.

/* ------------ Example functions ------------*/
// This function takes two UNSIGNED integers (type 'unsigned int') and returns the sum of them.
unsigned int AddUnsigned(unsigned int x, unsigned int y)
{
    return x + y;
}
// This function takes two signed integers (type 'int') and returns the sum of them.
int AddSigned(int x, int y)
{
    return x + y;
}
// This function does not return anything, but accepts a string (character array) as input and prints it to the console.
void WriteToConsole(const char* string)
{
    std::cout << string << '\n';
}

void Demo_Functions()
{
    /* ------------ Calling functions ------------*/
    unsigned int X = 30;
    unsigned int Y = 60;
    unsigned int Sum = AddUnsigned(X, Y); // Sum is the value returned by AddUnsigned, i.e X+Y = 90

    int SignedX = -15;
    int SignedY = 10;
    int SignedSum = AddSigned(SignedX, SignedY); // SignedSum is the value returned by AddSigned, i.e SignedX+SignedY = -5

    // Functions do not need to be called with variables, you can pass arguments to them directly like so:
    int SignedSum2 = AddSigned(-15, 10); // SignedSum2 = -5

    /* ------------ Operators ------------*/
    // Operators can be seen as functions, but the name is replaced by a symbol.
    // For example, instead of the AddSigned function, one can use the pre-defined '+' operator to add two signed integers.
    // In fact, the AddSigned function is just a wrapper for the '+' operator.
    int SignedSum3 = SignedX + SignedY; // This would have the same result as AddSigned(SignedX, SignedY)

    // There are a lot of operators in C++, but the most common ones are:
    // 
    // The arithmetic operators: + (ADD), - (SUBTRACT), / (DIVIDE), * (MULTIPLY), % (MODULO), < (LESS THAN)
    //							 > (GREATER THAN), <= (LESS OR EQUAL), >= (GREATER OR EQUAL)
    // The logic operators: && (AND), || (OR), != (NOT EQUAL), == (EQUAL)
    // The assignment & arithmetic assigment operators: =, +=, -=, /=, *=
    // The bit operators: <<, >>, ^, |, &
    // The ones most important to memorize are the logic operators, the assignment operator (only =) and the arithmetic operators (not modulo).

    // Operators have return values too, for example the logic equal operator (==) will return 'true' (boolean) if the two values
    // being compared are equal, or false if they aren't.
    bool SignedEquality = (SignedSum3 == SignedSum);
    bool UnsignedEquality = (AddUnsigned(X, Y) == Sum);
}