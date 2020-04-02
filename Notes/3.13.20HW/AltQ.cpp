#include <iostream>
using namespace std;

//Chunk!
class Chunk{
public:
    int value;
    Chunk *next;

    Chunk() {
        value = 0;
        next = NULL;
    }

};

//Queue of "Chunks"
class Queue{
public:
    Chunk *head;
    Chunk *tail; //*This will make it easier to add/remove

    Queue() {
        head = NULL;
        tail = NULL; //*
    }

    //1. Add chunks to the Q (enqueue)
    void enqueue(int x) {
        Chunk *temp = new Chunk;
        temp->value = x;

        if (tail == NULL) {
            head = temp;
            tail = temp; //*
        }
        else {
            tail = head;
            while (tail->next != NULL)
            {
                tail = tail->next;
                //cout <<"debug" << endl;
            }
            tail->next = temp;
        }
    }
    
    //2. Remove chunk from the Q (dequeue)
    void dequeue() {
        if (head == NULL) {
            cout << "Empty Q, Nothing to delete" << endl;
            return;
        }
        else if (head->next == NULL) {
            //Only one chunk test ^, [Delete it and set head to NULL]
            cout << "Deleting: " << head->value << endl;
            delete head;
            head = NULL;
            tail = NULL; //*
        }
        else {
           Chunk *temp;
            temp = head;
            head = head->next;
            
            cout << "About to delete: " << temp->value << endl;
            delete temp;
        }
    }
    
    //3. Display the contents of the Q
    void printContents() {
        if (head == NULL) {
            cout << "Empty Q, Nothing to display." << endl;
        }
        else {
            Chunk *temp;
            temp = head;
            cout << "-------------------------------" << endl;
            while (temp != NULL) {
                cout << temp->value << " ----> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
            cout << "-------------------------------" << endl;
        }
    }
};

int main() {
    Queue Q;
    int value, choice;
    while(1) {
        cout << "Press [1] to add (enQ) " << endl;
        cout << "Press [2] to remove (dQ) " << endl;
        cout << "Press [3] to display " << endl;
        cout << "Press [ANY] key to QUIT " << endl;
        cin >> choice;

        switch(choice) {
            case 1: 
                    cout << "Add what? " << endl;
                    cin >> value;
                    Q.enqueue(value);
                    break;
            case 2:
                    Q.dequeue();
                    break;
            case 3:
                    Q.printContents();
                    break;
            default:
                cout << "Goodbye!" << endl;
                exit(1);

        }
    }

}