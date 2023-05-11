/* ------------ Introduction ------------*/
// Note: this guide assumes you have a decent understanding of structures and how to initialize & use them.
// A class is mostly the same as a structure, but classes generally have private members by default
// This means that the class members can not be accessed from outside of the class itself (BY DEFAULT)
// You can change this behaviour by using the 'public:' and 'private:' keywords.

/* ------------ Examples ------------*/
class ExampleClass1
{
public: // This will make any class member defined after this point public (accessible from outside)
	unsigned int DataMember1;
	unsigned int DataMember2;

	// Constructor function
	ExampleClass1(unsigned int memb1val, unsigned int memb2val)
	{
		DataMember1 = memb1val;
		DataMember2 = memb2val;
	}

	// This is an example of a class member function.
	// It can access its own members directly.
	unsigned int SumOfDataMembers()
	{
		return DataMember1 + DataMember2;
	}
};

void Demo_Classes()
{
	// Class initialization
	ExampleClass1 Class1(1, 4);
	// This will initialize Class1 with [DataMember1 = 1] and [DataMember2 = 4], as can be seen in the ExampleClass1 constructor
	// To call class member functions, simply use the same syntax as you would when accessing the data members.
	unsigned int Sum = Class1.SumOfDataMembers(); // Returns DataMember1+DataMember2 = 5
}