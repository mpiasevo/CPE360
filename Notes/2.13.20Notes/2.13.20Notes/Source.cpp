#include <iostream>
using namespace std;

class ChromeTab {
public:
	//attributes
	int length;
	int width;
	ChromeTab *next;

	//constructor
	ChromeTab() {
		length = 100;
		width = 50;
		next = NULL;
	}

	//functions; lets not bother just yet

};

int main() {
	//first tab
	ChromeTab *first;
	first = new ChromeTab;
	first->length = 200;
	first->width = 100;

	//second tab
	first->next = new ChromeTab;
	first->next->length = 400;
	first->next->width = 400;

	//third tab
	first->next->next = new ChromeTab;
	first->next->next->length = 1000;
	first->next->next->width = 300;

	//let's add a new chunk, such that this is now the FIRST tab
	ChromeTab *another = new ChromeTab;

	//let's get this new "another" tab to point to the current first
	another->next = first;
	first = another;

	//let's add something in the middle
	another = new ChromeTab;
	another->next = first->next->next;
	first->next->next = another;

	//let's delete the last tab
	delete first->next->next->next->next;
	first->next->next->next->next = NULL;

	//let's delete something in the middle
	another = first->next->next;
	first->next->next = first->next->next->next;
	delete another;

	//lets just loop through the structure and print stuff
	another = first;
	while (another != NULL) {
		cout << "--------" << endl;
		cout << "Length: " << another->length << endl;
		cout << "Width: " << another->width << endl;
		another = another->next;
	}

	return 1;
}