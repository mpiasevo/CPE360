#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class meetings {
private:
	ofstream writefile;
	ifstream readfile;

public:
	meetings() {
		writefile.open("meetings.txt", ios::app);

	}





};

int main() {
	char choiceDay;
	char choiceTime;

	cout << "Pick a day for your meeting." << endl;
	cout << "=====================================================" << endl;
	cout << "[1] Monday" << endl;
	cout << "[2] Tuesday" << endl;
	cout << "[3] Wednesday" << endl;
	cout << "[4] Thursday" << endl;
	cout << "[5] Friday" << endl;
	cin >> choiceDay;
	if (choiceDay == '1') {
		cout << " " << endl;
		cout << "Please choose a time for your meeting: " << endl;
		cout << "=====================================================" << endl;
		cout << "[1] 12:00 PM - 1:00 PM" << endl;
		cout << "[2] 1:00 PM - 2:00 PM" << endl;
		cout << "[3] 2:00 PM - 3:00 PM" << endl;
		cout << "[4] 3:00 PM - 4:00 PM" << endl;
		cin >> choiceTime;
	 }
	else {
		cout << "Invalid choice, please try again: " << endl;
	}
	return 1;
}