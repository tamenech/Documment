
#include <iostream>
using namespace std;

struct Node {
	int data;        // data feiled
	Node *next;        // pointer to the next node
	Node *prev;             //pointer to the next node
};

class DoublyLinkedList {
	private:
		Node *head;    // head pointer

	public:
		//constructor
		DoublyLinkedList() {
			head = NULL;
		}
		//function prototypes
		void insertAtBeginning(int value);
		void insertAtEnd(int value);
		void insertAtPosition(int value, int position);
		void deleteFromBeginning();
		void deleteFromEnd();
		void deleteFromPosition(int position);
		void display();
		void exit();

};

void DoublyLinkedList::insertAtBeginning(int value) {
	Node *newNode = new Node();
	newNode->data = value;
	newNode->next = head;
	newNode->prev = NULL;
	if (head != NULL) {
		head->prev = newNode;    //update the pervious pointer for the cuurent head
	}
	head = newNode;       //update head to the new node
	cout << "Inserted"   " " << value << " "  "at the beginning.\n";

}

void DoublyLinkedList::insertAtEnd(int value) {
	Node *newNode = new Node();
	newNode->data = value;
	newNode->next = NULL;

	if (head = NULL) {           //if the List is empty
		newNode->prev = NULL;
		head = newNode;
	}   else {
		Node *temp = head;
		while (temp->next != NULL ) { //Traverse to the Last node
			temp = temp->next;
		}
		temp->next = newNode;      //Link the Last node to the new node
		newNode->prev = temp;       //Link new node to the previous last node
	}
	cout << "Inserted " << value << " at the end\n";

}
// Insert the node about the position

void DoublyLinkedList::insertAtPosition(int value, int position) {
	if (position < 1) {
		cout << "Invalid position" << endl;
		return;
	}
	Node *newNode = new Node();
	newNode->data = value;
	if (position == 1) {
		insertAtBeginning(value);
		return;
	}
	Node *temp = head;
	for (int i = 1; i < position - 1 && temp != NULL; i++) {
		temp = temp->next ;
	}
	if (temp == NULL) {
		cout << "position out of range\n";
		return;
	}
	newNode->next = temp->next ;
	if (temp->next != NULL) {
		temp->next->prev = newNode;
	}
	temp->next = newNode;
	newNode->prev = temp;
	cout << "Inserted " << value << " at position " << position << ".\n";
}

// delete the node from beginning
void DoublyLinkedList::deleteFromBeginning() {
	if (head = NULL) {
		cout << "the list is empty.Nothin to delete.\n";
		return;
	}
	Node *temp = head;
	head = head->next;
	if (head != NULL) {
		head->prev = NULL;
	}
	delete temp;     // free the memory of the old head
	cout << "Deleted nodefrom the beginning.\n";
}
//  delete  node from the end

void DoublyLinkedList::deleteFromEnd() {
	if (head == NULL) {
		cout << "The list is empty.Nothin to delete.\n";
		return;
	}
	Node *temp = head;
	if (temp->next == NULL) {  // if there is only one node
		head = NULL;
		delete  temp;
		cout << "Deleted node from the end" << endl;
		return;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->prev->next = NULL;  //update the second to last node is next pointer
	delete temp;
	cout << "Dleted node from the end" << endl;
}

// Delete node from position
void DoublyLinkedList::deleteFromPosition(int position) {
	if (position < 1) {
		cout << "Invalid position" << endl;
		return;
	}
	if (head == NULL) {
		cout << "The list is empty. Nothing to delete:" << endl;
		return;
	}
	if (position == 1) {
		deleteFromBeginning();
		return;
	}
	Node *temp = head;
	for (int i = 1; i < position && temp != NULL; i++) {      //travese to desired position

		temp = temp->next;
	}
	if (temp == NULL) {
		cout << "position out of range" << endl;
		return;
	}
	temp->prev->next = temp->next;
	if (temp->next != NULL) {
		temp->next->prev = temp->prev;
	}
	delete temp;                                          // free the memory of node
	cout << "Deleted node from position"  " " << position << ".\n";
}
// display the function

void DoublyLinkedList::display() {
	if (head == NULL) {
		cout << "The list is empty.\n";
		return;
	}
	Node *temp = head;
	cout << "Doubly Linked List:" ;
	while (temp != NULL) {
		cout << temp->data << " <-> ";
		temp = temp->next;
	}
	cout << "NULL\n";

}

// main function
int main() {
	DoublyLinkedList dll;
	int choice, value, position;

	while (true) {
		cout << " operation on Doubly Linked List:\n";
		cout << "1. Insert at the beginning.\n";
		cout << "2. Insert at the end.\n";
		cout << "3. Insert at a specific position.\n";
		cout << "4. Delete from the beginning.\n";
		cout << "5. Delete from the end.\n";
		cout << "6. Delete from specific position.\n";
		cout << "7. Display the list \n";
		cout << "8. Exit\n";

		cout << "Enter your choice:" ;
		cin >> choice;


		switch (choice) {
			case 1:
				cout << "Enter value to insert: ";
				cin >> value;
				dll.insertAtBeginning(value);
				break;
			case 2:
				cout << "Enter value to insert: ";
				cin >> value;
				dll.insertAtEnd(value);
				break;
			case 3:
				cout << "Enter value to insert: ";
				cin >> value;
				cout << "Enter position: ";
				cin >> position;
				dll.insertAtPosition(value, position);
				break;
			case 4:
				dll.deleteFromBeginning();
				break;
			case 5:
				dll.deleteFromEnd();
				break;
			case 6:
				cout << "Enter position to delete: ";
				cin >> position;
				dll.deleteFromPosition(position);
				break;
			case 7:
				dll.display();
				break;
			case 8:
				cout << " Exiting...\n";
				return 0;


			default:
				cout << "Invaid choices.Try again" << endl;
		}
	}
	return 0;
}



































































































































