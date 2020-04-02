#include <iostream>

using namespace std;
//Recursion very powerful tool to solve problems in computer science (problems can often be broken down into little steps)

void hanoi(int N, char S, char I, char D) {
	static int counter = 0; //static int shares the same int in all the "boxes"

	if (N == 1) {
		//base case
		cout << ++counter << ": Move disc " << N << " from " << S << " to " << D << endl;
	}
	else {
		//recurrent relationship
		hanoi(N - 1, S, D, I); //n-1 from S --> I
		cout << ++counter << ": Move disc " << N << " from " << S << " to " << D << endl;
		hanoi(N - 1, I, S, D);
	}
}

int main() {
	int N;
	char S = 'S', I = 'I', D = 'D';

	cout << "How many disks?: " << endl;
	cin >> N;
	hanoi(N, S, I, D);

	return 1;
}

/* void towersOfHanoi(int disk, char Source, char Aux, char Destination)
{
	if (disk == 1)
	{
		cout << "Move Disk " << disk << " from " << Source << " to " << Destination << endl;
		return;
	}

	towersOfHanoi(disk - 1, Source, Destination, Aux);
	cout << "Move Disk " << disk << " from " << Source << " to " << Destination << endl;
	towersOfHanoi(disk - 1, Aux, Source, Destination);
}

int main() {
	int disk;

	cout << "Please enter the number of disks in the Towers of Hanoi puzzle: " << endl;
	cin >> disk;
	cout << "This is the solution, the disks are ordered from top to bottom with 1 being the top. A, B, and C are the pegs from left to right with the leftmost one being A." << endl;
	towersOfHanoi(disk, 'A', 'B', 'C');

	system("pause");
	return 1;
}

*/
