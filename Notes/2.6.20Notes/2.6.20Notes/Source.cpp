#include <iostream>
using namespace std;

#define MACRO 10 //this is not a variable, this is a macro (label)

int MAX = 10; //this is a global variable, everyone can access MAX, but this is BAD practice, can be changed by any scope and will be changed for all scopes
const int bigOlMax = 20; //this one cannot be changed
//this is different from static variable, static can shared accross functions
int main() {
	int var = 10; //unitiallized will be assigned a random value
	int *pal; //friendly kind of variable
	int another = 5;
	/*
		* pal is a "pointer"
		* it can only store addresses, and never literal values
	*/

	pal = &var; //now pal knows the address of var

	cout << "The value of this variable: " << var << endl;
	cout << "The address of this variable: " << &var << endl << endl; //the address for the first bit of the variable var; compiler immediatly converts "var" to the address
	/* Once the compiler has the address it can immediatly "visit" it in the symbol table and see its value
		The address will not stay the same everytime you compile the code
			This is because memory is a shared space, the program will be placed in random spots in memory that are free
			(Like a parking lot)
	*/

	//var = var + 10
	// *pal = dereferencing a pointer
	*pal = *pal + 10; //pal pays a visit to var and changes the value of var to 20

	cout << "The value of var after pal pays a visit: " << var << endl;

	//==================================================
	//now lets get pal to grab the address of another
	//(meaning pal will forget about var)

	pal = &another;
	*pal = 500;
	cout << "The value of another after pal changes to visiting him: " << another << endl << endl;

	if (var > 0) {
		int canYouSeeMe = 10;
		cout << "Within the if block canYouSeeMe is: " << canYouSeeMe << endl << endl;
	} //as soon as the if scope ends, the variables born inside the if are DESTROYED
	// cout << "Can you see me now? " << canYouSeeMe << endl; (This will not work because it is not within the scope)

	cout << "This is MAX: " << MAX << endl;
	MAX = 40;
	cout << "This is MAX after he is changed from a different scope because he is a global variable: " << MAX << endl;

	for (int i = 0; i < MACRO; i++) {
		//this uses MACRO which is set as 10
	}

	return 1;
}