#include <iostream>
using namespace std;

/*
*Stacks
    -Add and remove FRONT (LIFO) [Last in First Out]
*Queues
    -Add and remove from OPPOSITE ENDS (FIFO) [First in First Out]
*Linked Lists
    -Add and remove anything from anywhere
*/

class Chunk{
public:
    int value; //amazon would use product recommendations
    Chunk *next;

    Chunk() {
        value = 0;
        next = NULL;
    }
};

//Stack of Chunks
class Stack {
public:
    Chunk *top;

    Stack() {
        top = NULL;
    }

    //1. PUSH [add a new element]
    void push(int x) {
        //add this value 'x' into the structure
        Chunk *another;
        another = new Chunk;
        another->value = x;

        //case1: structure is empty: Simply make the new value the "top"
        if(top == NULL) {
            top = another;
        }
        //case2: structure is not empty, has one or more
        else {
            another->next = top;
            top = another;
        }
    }

    //2. POP [remove an element]
    void pop(){
        //case1: stack is empty
        if(top == NULL) {
            cout << "Empty Stack, nothing to delete." << endl;
            return;
        }
        //case2: stack is not empty
        else {
            Chunk *another;
            another = top;
            top = top->next;
            
            cout << "About to delete: " << another->value << endl;
            delete another;
        }
    }

    //3. DISPLAY [show me the contents]
    void display() {
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

    void display3() {
        if (top == NULL) {
            cout << "Empty" << endl;
            return;
        }
        else if (top->next == NULL) {
            cout << "Only one Item" << endl;
        }
        else if (top->next->next == NULL) {
            cout << "Only two Items" << endl;
        }
        else {
            cout << top->next->next->value << endl;
        }
    }
};


int main() {
    Stack myStack;
    int choice, value;
    //we add 5, 6 ,3 ,9 ,10
    myStack.push(5);
    myStack.push(6);
    myStack.push(3);
    myStack.push(9);
    myStack.push(10);

    myStack.display();

    while(1) {
        cout << "Press 1 to ADD" << endl;
        cout << "Press 2 to POP" << endl;
        cout << "Press 3 to DISPLAY" << endl;
        cout << "Press 4 to DISPLAY3" << endl;
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
                myStack.display();
                cout << "----------------------" << endl;
                break;

            case 4:
                cout << "----------------------" << endl;
                myStack.display3();
                cout << "----------------------" << endl;

            default:
                cout << "Goodbye!" << endl;
                exit(1);
        }
    }
    
}