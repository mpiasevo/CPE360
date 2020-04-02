#include <iostream>
using namespace std; 

int getNthTermFibonnaci(int n) {
    if (n == 0 || n == 1) {
        return (n);
    }
    else {
        return(getNthTermFibonnaci(n-1)+getNthTermFibonnaci(n-2));
    }
}

int main () {
    int choice;
    cout << "Choose the Nth term of Fibonnaci: " << endl;
    cin >> choice;
    for (int i = 1; i <= choice; i++) {
        cout << getNthTermFibonnaci(i) << " ";
    }
}