#include <iostream>
using namespace std;

class Chunk {
    public:
    int value;
    Chunk *next;

    Chunk() {
        value = 0;
        next = NULL;
    }
};

void printContents(Chunk *start) {
    if(start == NULL) {
        cout << "This is an empty list!" << endl;
        return;
    }
    else {
        while(start != NULL) {
        cout << start->value << " --> ";
        start = start->next;
        }
        cout << "NULL" << endl;
        cout << "____________________" << endl;
    }
}

int main() {
    Chunk *head, *another;

    //Step 1:   A. Get a chunk
    head = new Chunk;
    head->value = 1;
    //          B. A second chunk
    head->next = new Chunk;
    head->next->value = 2;
    //          C. A third chunk
    head->next->next = new Chunk;
    head->next->next->value = 3;
    printContents(head);

    //Step 2:   Add and remove a chunk from the FRONT
    another = new Chunk;
    another->next = head;
    head = another;
    printContents(head);
    //This is the deleting part
    another = head; //Redundant step, already pointing there
    head = head->next;
    delete another;
    printContents(head);

    //Step 3:   Add and delete a new chunk at the END
    another = new Chunk;
    head->next->next->next = another;
    printContents(head);
    //Deleting Part
    another = head->next->next->next; //Redundant step, already pointing there
    head->next->next->next = NULL;
    delete another;
    printContents(head);

    //Step 4:   Add chunk and delete from MIDDLE
    another = new Chunk;
    another->next = head->next->next;
    head->next->next = another;
    printContents(head);
    //Deleing Part
    another = head->next->next; //Redundant step, already pointing there
    head->next->next = another->next;
    delete another;
    printContents(head);

    return 1;
}