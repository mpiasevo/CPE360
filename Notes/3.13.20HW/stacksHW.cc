#include <iostream>
using namespace std;

class Chunk {
public:
    int value;
    Chunk *next;

    Chunk () {  //Chunk.value initialized to 0, chunk.next initialized to NULL
        value = 0;
        next = NULL;
    }
};

class Stack {
public:
    Chunk *top;

    Stack() {
        top = NULL; //Stack.top initialized to NULL
    }

    void push(int v) {
         Chunk *another;
        another = new Chunk;
        another->value = v;

        //check for empty structure
        if (top == NULL) {
            top = another;
        }
        //not empty:
        else {
            another->next = top;
            top = another;
        }
    }

    void pop(){
        //check for empty stack
        if(top == NULL) {
            cout << "Empty Stack, nothing to delete." << endl;
            return;
        }
        //not empty:
        else {
            Chunk *another;
            another = top;
            top = top->next;
            
            cout << "About to delete: " << another->value << endl;
            delete another;
        }
    }

    void displayContents() {
        //check for empty stack
        if(top == NULL) {
             cout << "Empty Stack, nothing to display." << endl;
            return;
        }
        else {
            Chunk *another;
            another = top;

            while(another != NULL) {
                cout << another->value << " ---> ";
                another = another->next;
            }
            cout << "NULL" << endl;
        }
    }

};



int main() {
    Stack myStack;
    int choice, value;
    //initialize with 1, 2, 3, 4, 5
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    myStack.displayContents();

    while(1) {
        cout << "Press 1 to ADD [push]" << endl;
        cout << "Press 2 to DELETE [pop]" << endl;
        cout << "Press 3 to DISPLAY" << endl;
        cout << "Press ANY key to quit" << endl;
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Add what?" << endl;
                cin >> value;
                myStack.push(value);
                break;

            case 2:
                myStack.pop();
                break;

            case 3:
                cout << "----------------------" << endl;
                myStack.displayContents();
                cout << "----------------------" << endl;
                break;

            default:
                cout << "Goodbye!" << endl;
                exit(1);
        }
    }

}