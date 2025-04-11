#include <iostream>
using namespace std;

struct Node {
	int data;       //Data field
	Node *prev;      //pointer tothe previous node
	Node *next;      //pointer to the next node
};

class CircularDoublyLinkedList {
	private:
		Node *tail;      //pointer to the last node in the list

	public:
		//constructor
		CircularDoublyLinkedList() {
			tail = NULL;
		}
		//function protoypes
		void insertAtBeginning(int value);
		void insertAtEnd(int value);
		void insertAtPosition(int value, int position);
		void deleteFromBeginning();
		void deleteFromEnd();
		void deleteAtFromPosition(int value);
		void display();
		void exit();

};

//Inserted the node at the beginning
void CircularDoublyLinkedList::insertAtBeginning(int value) {
	Node *newNode = new Node();
	newNode->data = value;

	if (tail == NULL) {     // if the list is empty
		newNode->next = newNode;
		newNode->prev = newNode;
		tail = newNode;
	} else {
		Node *head = tail->next;  // the current first node
		newNode->next = head;
		newNode->prev = tail;
		head->prev = newNode;
		head->prev = newNode;
	}
	cout << "Inserted " << value << " at the beginning.\n";
}

//Inserted the noe at the end
void CircularDoublyLinkedList::insertAtEnd(int value) {
	Node *newNode = new Node();
	newNode->data = value;

	if (tail == NULL) {   //if the list is empty
		newNode->next = newNode;
		newNode->prev = newNode;
		tail = newNode;
	} else {
		Node *head = tail->next;
		newNode->next = head;
		newNode->prev = tail;
		tail->next = newNode;
		head->prev = newNode;
		tail = newNode;           //update the tail to the new node
	}
	cout << "Inserted " << value << " at the end.\n";

}

// Inserted the node at specific position
void CircularDoublyLinkedList::insertAtPosition(int value, int position) {
	if (position < 1) {
		cout << " Invalid position!\n";
		return;
	}
	if (position == 1) {   //Insert at the beginning
		insertAtBeginning(value);
		return;
	}
	Node *newNode = new Node();
	newNode->data = value;
	Node *temp = tail->next;      //strat at the beginning
	for (int i = 1; i < position - 1 && temp != tail; i++) {
		temp = temp->next;
	}
	if (temp == tail && position < 1) {
		cout << "position out of range \n";
		delete newNode;
		return;
	}
	newNode->next = temp->next;
	newNode->prev = temp;

	temp->next->prev = newNode;
	temp->next = newNode;
	if (temp == tail) {           //if add at the end ,update tail
		tail = newNode;
	}
	cout << "Inserted " << value << " at position " << position << ".\n";
}

//Delete from the beginnijg
void CircularDoublyLinkedList::deleteFromBeginning() {
	if (tail == NULL) {
		cout << "The list is empty. Nothing to delete.\n";
		return;
	}

	Node *head = tail->next;

	if (tail == head) {  // If there's only one node
		tail = NULL;
	} else {
		Node *newHead = head->next;
		newHead->prev = tail;
		tail->next = newHead;
	}

	delete head;
	cout << "Deleted node from the beginning.\n";
}

// delete the node from the list

void CircularDoublyLinkedList::deleteFromEnd() {
	if (tail == NULL) {
		cout << "The list is empty.Nothing to delete.\n";
		return;
	}
	Node *head = tail->next;
	if (tail == head) {       //if there's only one node
		tail = NULL;
	} else {
		Node *newTail = tail->prev;
		newTail->next = head;
		head->prev = newTail;
		delete tail;
		tail = newTail;
	}
	cout << "Deleted node from the end.\n";
}

// delete node from specific position
void CircularDoublyLinkedList::deleteAtFromPosition(int position) {
	if (position < 1) {
		cout << "Invalid position!\n";
		return;
	}
	if (tail == NULL) {
		cout << "The list is empty.Nothing to delete.\n";
		return;
	}
	if (position == 1) {       //Delete from the beginning
		deleteFromBeginning();
		return;
	}
	Node *temp = tail->next;
	for (int i = 1; i < position && temp != tail; i++) {
		temp = temp->next;
	}
	if (temp == tail->next && position < 1) {
		cout << "position out of range!\n";
		return;

	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	if (temp == tail) {              //if deleted node is the last node
		tail = temp->prev;
	}
	delete temp;
	cout << "Deleted node from position"  " " << position << ".\n";
}

// print all nodes from the list
void CircularDoublyLinkedList::display() {
	if (tail == NULL) {
		cout << "The list is empty.\n";
		return;
	}
	Node *temp = tail->next;
	cout << " Circular Doubly Linked List:";
	do {
		cout << temp->data << " <->" ;
		temp = temp->next;
	} while (temp != tail->next );
	cout << " (back to head)\n";



}



// main function
int main() {
	CircularDoublyLinkedList cdll;
	int choice, value, position;

	while (true) {
		cout << "\nOperation on Circular Doubly Linked List:\n";
		cout << "1. Insert at the beginning\n";
		cout << "2. Insert at the end\n";
		cout << "3. Insert at a specific positon\n";
		cout << "4. Delete from the beginning\n";
		cout << "5. Delete from the end\n";
		cout << "6. Delete from a specific position\n";
		cout << "7. Display the list\n";
		cout << "8. Exit \n";
		cout << "Enter your choice:";
		cin >> choice;


// value to display using switch
		switch (choice) {
			case 1:
				cout << "Enter value to insert:";
				cin >> value;
				cdll.insertAtBeginning(value);
				break;
			case 2:
				cout << "Enter value to insert:";
				cin >> value;
				cdll.insertAtEnd(value);
				break;
			case 3:
				cout << "Enter value to insert:";
				cin >> value;
				cout << " Enter position:";
				cin >> position;
				cdll.insertAtPosition(value, position);
				break;
			case 4:
				cdll.deleteFromBeginning();

				break;
			case 5:
				cdll.deleteFromEnd();
			case 6:
				cout << "Enter position to delete:";
				cin >> position;
				cdll.deleteAtFromPosition(position);
				break;
			case 7:
				cdll.display();
				break;
			case 8:
				cout << " Exiting .\n";

				return 0;
			default:
				cout << "Invalid choice.Try again" << endl;
		}
	}
	return 0;
}






























































































































































