#include <iostream>
using namespace std;

class amazonItemsForSale { //allows you to have a million items instead of creating individual variables to store items
//public: private: two extremes, between the two is protected:
public:
	//1. What is the physical look and feel of items of this type?
		//["atributes"]
	float price;
	int sellerID; 
	//2. When we create a new object, what does it look like?
		//["constructor"] special function that "initializes" atributes to a default value
	amazonItemsForSale() {
		price = 0.0;
		sellerID = 100;
	}
	//3. What functions are allowed for items of this type?
	void addItemToCart() {
		//implement this function
		cout << "Item added to cart" << endl;
	}
};

int main() 
{
	int x;
	amazonItemsForSale item1;

	item1.price = 38.50;
	cout << "Price of this new item: $" << item1.price << endl;
	item1.sellerID = 900;
	cout << "Seller ID is: " << item1.sellerID << endl << endl;

	item1.addItemToCart();

	// =============================================================
	// Creating variables that have no name
	// These kinds of variables reside in the "Heap": a secial zone in the memory
	// =============================================================
	
	//First, create a pointer
	amazonItemsForSale *customer;
	amazonItemsForSale *item2;
	//get a new item from the heap
	customer = new amazonItemsForSale; //nameless... just an address
	item2 = new amazonItemsForSale;
	//arrow operator as opposed to the dot operator
	customer->price = 40.0;
	customer->sellerID = 400;
	
	item2->price = 100.0;
	item2->sellerID = 123;

	cout << "First box in the heap!" << endl;
	cout << customer->price << " " << customer->sellerID << endl;

	cout << "Second box in the heap!" << endl;
	cout << item2->price << " " << item2->sellerID << endl;

	customer = NULL; //grounds the pointer BUT leaves the box in the heap without access to it.
	//more traditionally called a memory leak! Not good

	return 1;
}