#include <iostream>
using namespace std;

//Linked List, you can add or remove chunks from WHEREVER you want.
class Chunk{
public:
    int value;
    Chunk *next;

    Chunk() {
        value = 0;
        next = NULL;
    }

};

//LL of Chunks
class LinkedList {
public:
    Chunk *head;
    int length;

    LinkedList() {
        head = NULL;
        length = 0;
    }
    //1. Add something to list
    void addAtPosition(int value, int position) {
        if (position > 0 && position <= length + 1) {
            Chunk *temp = new Chunk;
            temp->value = value;

            if (position == 1) {        //Beginning
                temp->next = head;
                head = temp;
            }
            else if (position > 1 && position <= length) {      //Middle
                Chunk *helper = head;
                //take helper to position - 1
                for (int i = 1; i < position - 1; i++){
                    helper = helper->next;
                    // cout << "Helper at: " << helper->value << endl; //debug statement
                }

                temp->next = helper->next;
                helper->next = temp;
            }
            else {          //END; Technically the code will work without this else
                Chunk *helper = head;
                while (helper->next != NULL) {
                    helper = helper->next;
                }
                helper->next = temp;
            }
            length++; //(step on your right foot) DON'T FORGET IT
        }
        else {
            cout << "Can't do that, invalid position" << endl;
        }
    }
    //2. Remove from list
    void removeFromPosition(int position) {
        if (position > 0 && position <= length) {
            if (position == 1 && length == 1) {
                delete head;
                head = NULL;
            }
            else if (position == 1 && length > 1) {                    //Beginning
                Chunk *temp = head;
                head = head->next;
                delete temp;
            }
            else {       //Middle & End
                Chunk *temp, *slow;
                temp = slow = head;
                for (int i = 1; i <= position; i++) {
                    slow = temp;
                    temp = temp->next;
                   // cout << "Slow at: " << slow->value << endl; //debug statement
                   // cout << "Temp at: " << temp->value << endl; //debug statement
                }
                slow->next = temp->next;
                delete temp;
            }

            length--;
        }
        else {
            cout << "Position invalid: Will not delete" << endl;
        }
    }
    //3. Display
    void displayContents(){
        //Same as Stacks/Qs
         if (head == NULL) {
            cout << "Empty LL, Nothing to display." << endl;
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
    void removeEveryOtherNode(Chunk *head){
       if (head == NULL)  
        return;  
  
    Chunk *chunk = head->next;  
  
    if (chunk == NULL)  
        return;  
  
    /* Change the next link of head */
    head->next = chunk->next;    
  
    /* Recursively call for the new next of head */
    removeEveryOtherNode(head->next); 
    }

    void reverseLinkedList(){
    Chunk* current = head;
    Chunk* last = NULL, *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = last;
        last = current;
        current = next;
    }
    head = last;
    cout << "Linked list reversed" << endl;
    displayContents();
    }
};


int main() {
    LinkedList LL;
    int value = 100;
    int position = 3;

    LL.addAtPosition(1, 1);
    LL.addAtPosition(2, 2);
    LL.addAtPosition(3, 3);
    LL.addAtPosition(4, 4);

    int choice;
    while(1) {
        cout << "Press [1] to add " << endl;
        cout << "Press [2] to remove " << endl;
        cout << "Press [3] to display " << endl;
        cout << "Press [4] to reverse list" << endl;
        cout << "Press [5] to delete every other node" << endl;
        cout << "Press [ANY] key to QUIT " << endl;
        cin >> choice;

        switch(choice) {
            case 1: 
                    cout << "Add what? " << endl;
                    cin >> value;
                    cout << "What Position?" <<endl;
                    cin >> position;
                    LL.addAtPosition(value,position);
                    break;
            case 2:
                    cout << "What position would you like to delete?" << endl;
                    cin >> position;
                     LL.removeFromPosition(position);
                    break;
            case 3:
                    LL.displayContents();
                    break;
            case 4:
                    LL.reverseLinkedList();
                    break;
            case 5:
                    LL.removeEveryOtherNode(LL.head);
                    break;
            default:
                cout << "Goodbye!" << endl;
                exit(1);

        }
    }
}