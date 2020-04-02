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

    Queue() {
        head = NULL;
    }

    //1. Add chunks to the Q (enqueue)
    void enqueue(int x) {
        Chunk *temp = new Chunk;
        temp->value = x;

        if (head == NULL) {
            head = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
    }
    
    //2. Remove chunk from the Q (dequeue)
    //      [Remove from END: find out last chunk and DELETE]
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
        }
        else {
            //Like walking, goes to end and deletes, sets previous to NULL
            Chunk *chase, *follow;
            chase = follow = head;
            while(chase->next != NULL) {
                follow = chase;
                chase = chase->next;
            }
            follow->next = NULL;
            cout << "Deleting: " << chase->value << endl;
            delete chase;
        }
    }
    
    //3. Display the contents of the Q
    void display() {
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
                    Q.display();
                    break;
            default:
                cout << "Goodbye!" << endl;
                exit(1);

        }
    }

}