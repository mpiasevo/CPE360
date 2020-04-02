#include <iostream>
using namespace std;

//Signature of a function:
// 1. What does the function return
// 2. What is the name of the function
// 3. Arguments: what does the function need to do what it does
//Void auto returns to main
int add(int x, int y) {
	int result;
	result = x + y;
	return result;
}

int main() {
	/*
	int ageOfUser = 10;

	//cout << "Write Text Here" << endl;
	cout << "Give me your age: " << endl;
	cin >> ageOfUser;

	// == equality; != not equal; > < >= <=; && and;
	if (ageOfUser >= 16) {
		cout << "You are eligible for a liscense!" << endl;
	}
	else if (ageOfUser == 15) {
		cout << "Almost old enough to drive" << endl;
	}
	else {
		cout << "You are NOT eligible for a liscense!" << endl;
		cout << "You have to wait: " << 16 - ageOfUser << " years to drive." << endl;
	}
	*/

	int result;
	int a = 10, b = 20;
	result = add(5, 3);
	cout << "Sum of 5 and 3 is " << result << endl;

	result = add(add(a, b), add(a, b));
	cout << "Sum is " << result << endl;
	system("pause");
}