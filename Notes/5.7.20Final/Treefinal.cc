#include <iostream>
using namespace std;

/*
 *	I pledge my honor that I have abided by the Stevens Honor System
 *	Contributors: Marko Piasevoli
 *	
 *	CPE 360 Final Project :)
 *
 */

class TreeChunk {
	public:
		int data;
		TreeChunk *right;
		TreeChunk *left;

		TreeChunk() {
			data = 0;
			left = NULL;
			right = NULL;
		}
};

class BST{

	public:
		TreeChunk *root;
		BST(){
			root = NULL;
		}

		//1. Add new values to tree
		void add(int x){
			if (root == NULL) { //Check for empty tree
				root = new TreeChunk;
				root->data = x;
				cout << "Added first tree value: " << x << endl;
				return;
			}
			TreeChunk *slow, *fast;
			slow = fast = root;
			
			while (fast!= NULL) {
				if (x < fast->data) {
					slow = fast;
					fast = fast->left;
				}
				else if (x > fast->data) {
					slow = fast;
					fast = fast->right;
				}
				else {
					cout << "We do not allow duplicate numbers in the tree..." << endl;
					return;
				}
			}

			if (x < slow->data) {
				slow->left = new TreeChunk;
				slow->left->data = x;
			}
			else {
				slow->right = new TreeChunk;
				slow->right->data = x;
			}
			cout << "Successfully added: " << x << " to the tree!" << endl;
		}

		//2. Search for a value in the tree
		bool search(int key, TreeChunk *start) {
			
			//anchor value
			if (start == NULL) {
				cout << "Could not find the value you were looking for..." << endl;
				return false;
			}
			//Recursive Step
			else {
				if (key == start->data) {
					cout << "Success, value found in the tree!" << endl;
					return true;
				}
				if (key < start->data) {
					search(key, start->left);
				}
				else {
					search(key, start->right);
				}
			}
			return true;		
		}

		//3. Display contents of the tree
		void preorder(TreeChunk *start) {
			if (start == NULL) {
				return;
			}
			else {
				//Root, left, right
				cout << start->data << endl;
				preorder(start->left);
				preorder(start->right);
			}
		}

		void postorder(TreeChunk *start) {
			if (start == NULL) {
				return;
			}
			else {
				//left, right, root
				postorder(start->left);
				postorder(start->right);
				cout<< start->data << endl;
			}
		}

		void inorder(TreeChunk *start) {
			if (start == NULL) {
				return;
			}
			else {
				//left, root, right
				inorder(start->left);
				cout << start->data << endl;
				inorder(start->right);
			}
		}
		//Find min value for delete case 3:
		TreeChunk *findMin(TreeChunk *min){
			while(min->left != NULL)
				min = min->left;
			return min;
		}

		TreeChunk *deleteNodeS(TreeChunk *newroot, int key){
				//Empty Tree Test
			if (newroot == NULL) {
				cout << "Empty tree, nothing to delete... " << endl;
				return newroot;
			}

			//Search for the node
			TreeChunk *slow, *fast;
			slow = fast = newroot;

			while (fast != NULL && fast->data != key) {
				//keep going left or right
				if (key < fast->data) {
					slow = fast;
					fast = fast->left;
				}
				else {
					slow = fast;
					fast = fast->right;
				}
			}

			if(fast == NULL) {
				cout << "The node: " << key << " does not exist in this tree... " << endl;
				return fast;
			}

			//Classify the delete case
		//	cout << "Found the node, now trying to classify the type of delete." << endl;
			//	Case 1 (no child, left and right are NULL)
			if(fast->right == NULL && fast->left == NULL) {
			//	cout << "Looks like a Case 1 delete for: " << key << endl;

				if(slow->right == fast) {
					//the node is to the right of slow
					slow->right = NULL;
			//		cout << "About to delete: " << fast->data << endl;
					delete fast;
				}
				else if(slow->left == fast) {
					// the node is to the left
					slow->left = NULL;
			//		cout << "About to delete: " << fast->data << endl;
					delete fast;
				}
				else {
					newroot = NULL;
				}
				return newroot;
			}
			//	Case 2 (one child)
			else if ((fast->right == NULL && fast->left != NULL)||(fast->left == NULL && fast->right != NULL)) {
			//	cout << "Looks like a Case 2 delete for: " << key << endl;	
				if (fast->left != NULL) {
					if (slow->left == fast) {
						//fast is left of slow and child is left of fast
						slow->left = fast->left;
				//		cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
					else if (slow->right == fast) {
						//fast is right of slow and child is left of fast
						slow->right = fast->left;
				//		cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
					else {
						newroot = fast->left;
				//		cout << "About to delete: " << fast->data << endl;
						delete fast;
					}

				}
				if (fast->right != NULL) {
				//	cout << "Child is to the right of fast" << endl;
					if (slow->left == fast) {
						//fast is left of slow and child is right of fast
						slow->left = fast->right;
					//	cout << "About to delete: " << fast->data << endl;
						delete fast;
					}

					else if (slow->right == fast) {
						//fast is right of slow and child is right of fast
					
						slow->right = fast->right;
					//	cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
					else {
						newroot = fast->right;
					//	cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
				}
				return newroot;
			}
			//	Case 3 (two child)
			else {
				cout << "Looks like a Case 3 delete for: " << key << endl;
				
				TreeChunk *temp = findMin(fast->right);
				fast->data = temp->data;
				deleteNodeS(fast->right, temp->data);
			}
		}

		//4. Delete values from the tree
		void deleteNode(int key) {
			//Empty Tree Test
			if (root == NULL) {
				cout << "Empty tree, nothing to delete... " << endl;
				return;
			}

			//Search for the node
			TreeChunk *slow, *fast;
			slow = fast = root;

			while (fast != NULL && fast->data != key) {
				//keep going left or right
				if (key < fast->data) {
					slow = fast;
					fast = fast->left;
				}
				else {
					slow = fast;
					fast = fast->right;
				}
			}

			if(fast == NULL) {
				cout << "The node: " << key << " does not exist in this tree... " << endl;
				return;
			}

			//Classify the delete case
			cout << "Found the node, now trying to classify the type of delete." << endl;
			//	Case 1 (no child, left and right are NULL)
			if(fast->right == NULL && fast->left == NULL) {
				cout << "Looks like a Case 1 delete for: " << key << endl;

				if(slow->right == fast) {
					//the node is to the right of slow
					slow->right = NULL;
					cout << "About to delete: " << fast->data << endl;
					delete fast;
				}
				else if(slow->left == fast) {
					// the node is to the left
					slow->left = NULL;
					cout << "About to delete: " << fast->data << endl;
					delete fast;
				}
				else {
					cout << "About to delete: " << fast->data << endl;
					root = fast = slow = NULL;
				}
			}
			//	Case 2 (one child)
			else if ((fast->right == NULL && fast->left != NULL)||(fast->left == NULL && fast->right != NULL)) {
				cout << "Looks like a Case 2 delete for: " << key << endl;
				
				if (fast->left != NULL) {
					if (slow->left == fast) {
						//fast is left of slow and child is left of fast
						slow->left = fast->left;
						cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
					else if (slow->right == fast) {
						//fast is right of slow and child is left of fast
						slow->right = fast->left;
						cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
					else {
						root = fast->left;
						delete fast;
					}

				}

				if (fast->right != NULL) {
					if (slow->left == fast) {
						//fast is left of slow and child is right of fast
						slow->left = fast->right;
						cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
					
					else if (slow->right == fast) {
						//fast is right of slow and child is right of fast
						slow->right = fast->right;
						cout << "About to delete: " << fast->data << endl;
						delete fast;
					}
					else {
						root = fast->right;
						delete fast;
					}
				}
			}
			//	Case 3 (two child)
			else {
				cout << "Looks like a Case 3 delete for: " << key << endl;
				
				TreeChunk *temp = findMin(fast->right);
				fast->data = temp->data;
				cout << "About to delete: " << key << endl;
				fast->right = deleteNodeS(fast->right, temp->data);
			}
		}
};

int main(){
	BST myTree;
	int choice;
	int value;
	int traverse;
	//Initialize the Tree

	myTree.add(30);
	myTree.add(15);
	myTree.add(60);
	myTree.add(7);
	myTree.add(22);
	myTree.add(45);
	myTree.add(17);
	myTree.add(27);
	myTree.add(75);
	myTree.add(80);

	 while(1) {
		cout << "===============================================" << endl;
		cout << "Choose one of the following options: " << endl;
        cout << "Press [1] to add to the tree " << endl;
        cout << "Press [2] to delete from the tree " << endl;
        cout << "Press [3] to traverse the tree " << endl;
        cout << "Press [4] to search the tree" << endl;
        cout << "Press [ANY] key to QUIT " << endl;
        cin >> choice;
		cout << "===============================================" << endl;

       switch(choice) {
            case 1: 
                    cout << "Add what? " << endl;
                    cin >> value;
                    myTree.add(value);
                    break;
            case 2:
                    cout << "What number would you like to delete? " << endl;
                    cin >> value;
                     myTree.deleteNode(value);
                    break;
            case 3:
					cout << "What way would you like to traverse the tree? " << endl;
					cout << "Press [1] for preorder traversal " << endl;
					cout << "Press [2] for postorder traversal " << endl;
					cout << "Press [3] for inorder traversal " << endl;
					cin >> traverse;
					cout << "===============================================" << endl;
					if (traverse == 1) {
						myTree.preorder(myTree.root);
					}
					else if (traverse == 2) {
						myTree.postorder(myTree.root);
					}
					else if (traverse == 3) {
						myTree.inorder(myTree.root);
					}

					else
						cout << "That was not one of the options, returning to menu" << endl;
                   
                    break;
            case 4:
					cout << "What number would you like to search for? " << endl;
					cin >> value;
                    myTree.search(value, myTree.root);

                    break;

            default:
                cout << "Goodbye!" << endl;
                exit(1);

        }
    }

	/*
	//Search for values
	//1.Successful Search
	if(myTree.search(17, myTree.root))
		cout << "Success" << endl;
	else
		cout << "Could not find 17!" << endl;
	//2. Unsuccessful Search
	if(myTree.search(99, myTree.root))
		cout << "Sucess!" << endl;
	else
		cout << "Could not find 99" << endl;	
	
	cout << "=================================================" << endl;
	//Display Values :)
	myTree.preorder(myTree.root);
	//myTree.postorder(myTree.root);
	//myTree.inorder(myTree.root);
	cout << "=================================================" << endl;

	myTree.deleteNode(17);
	myTree.deleteNode(75);
	myTree.deleteNode(15);
	myTree.deleteNode(99);
	myTree.deleteNode(45);
	myTree.deleteNode(80);
	myTree.deleteNode(22);
	myTree.preorder(myTree.root);

	cout << "=================================================" << endl;
	*/
	return 0;
}
