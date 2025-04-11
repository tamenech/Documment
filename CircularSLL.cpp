#include <iostream>
using namespace std;

struct Node {
	int data;        //Data field
	Node *next;      //pointer to the next node
};

class CircularSinglyLinkedList {
	private:
		Node *tail;  //pointer to the last node

	public:
		//constructor
		CircularSinglyLinkedList() {
			tail = NULL;
		}

		//Function prototype
		void insertAtBeginning(int value);
		void insertAtEnd(int value);
		void insertAtPosition(int value, int position);
		void deleteFromBeginning();
		void deleteFromEnd();
		void deleteFromPosition(int position);
		void display();
		void exit();

};
// Inserted the list at the beginning

void CircularSinglyLinkedList::insertAtBeginning(int value) {
	Node *newNode = new Node();
	newNode->data = value;

	if (tail == NULL) {                         // If the list is empty
		tail = newNode;
		tail->next = newNode;                // Point to itself to form a circle
	} else {
		newNode->next = tail->next;            // Point to the current first node
		tail->next = newNode;               // Update the last node to point to the new first node
	}

	cout << "Inserted " << value << " at the beginning.\n";
}




//Insreted the list at the end

void CircularSinglyLinkedList::insertAtEnd(int value) {
	Node *newNode = new Node();
	newNode->data = value;

	if (tail == NULL) {     //If the list is empty
		tail = newNode;
		tail->next = newNode;
	} else {
		newNode->next = tail->next;     // point to the first node
		tail->next = newNode;
		tail = newNode;
	}
	cout << " Inserted "   " " << value << " "  " at the end.\n";
}

// Inserted list at the position

void CircularSinglyLinkedList::insertAtPosition(int value, int position) {
	if (position < 1) {
		cout << " Invalid position!\n";
		return;
	}
	Node *newNode = new Node();
	newNode->data = value;

	if (position == 1) {   // Insert at the beginning
		insertAtBeginning(value);
		return;
	}
	Node *temp = tail;      //start from first node
	for (int i = 1; i < position - 1 && temp != tail; i++) {
		temp = temp->next ;
	}
	if (temp == tail && position < 1) {
		cout << " position out of range!\n";
		return;
	}
	newNode->next = temp->next;
	temp->next = newNode;

	if (temp == tail) {    // if added at the update the tall
		tail = newNode;
	}
	cout << " Inserted" " " << value << " " " at position"   " "  << position <<  ".\n";
}


// delete node from beginning

void CircularSinglyLinkedList::deleteFromBeginning() {
	if (tail == NULL) {
		cout << "The list is empty.Nothing to delete\n";
		return;
	}
	Node *temp = tail->next;  // First node

	if (tail == temp) {  // Only one node in the list
		tail = NULL;
	} else {
		tail->next = temp->next;  // Point last node to the second node
	}

	delete temp;
	cout << "Deleted node from the beginning.\n";

}

// Delete from the end
void CircularSinglyLinkedList::deleteFromEnd() {
	if (tail == NULL) {
		cout << "The list is empty. Nothing to delete.\n";
		return;
	}

	Node *temp = tail->next;  // First node

	if (tail == temp) {  // Only one node in the list
		tail = NULL;
	} else {
		while (temp->next != tail) {  // Traverse to the second-last node
			temp = temp->next;
		}

		temp->next = tail->next;  // Point second-last node to the first node
		delete tail;              // Free memory of the last node
		tail = temp;              // Update the tail to the second-last node
	}

	cout << "Deleted node from the end.\n";
}

// delete node from position
void CircularSinglyLinkedList::deleteFromPosition(int position) {
	if (position < 1) {
		cout << "Invalid position!\n";
		return;
	}

	if (tail == NULL) {
		cout << "The list is empty. Nothing to delete.\n";
		return;
	}

	Node *temp = tail->next;

	if (position == 1) {         // Delete from the beginning
		deleteFromBeginning();
		return;
	}

	Node *prev = NULL;
	for (int i = 1; i < position && temp != tail->next; i++) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL ) {
		cout << "Position out of range!\n";
		return;

	}   else {
		prev->next = temp->next;

		// If deleted node is the last node



		delete temp;
		cout << "Deleted node from position " << position << ".\n";
	}


//  Display the node
	void CircularSinglyLinkedList::display() {
		if (tail == NULL) {
			cout << "The list is empty.\n";
			return;
		}

		Node *temp = tail->next;  // Start from the first node
		cout << "Circular Linked List: ";
		do {
			cout << temp->data << " -> ";
			temp = temp->next;
		} while (temp != tail->next);  // Stop when we circle back to the first node
		cout << "(back to head)\n";
	}
// main function

	int main() {
		CircularSinglyLinkedList csll;
		int choice, value, position;

		while (true) {
			cout << "\nOperations on Circular Singly Linked List:\n";
			cout << "1. Insert at the beginning\n";
			cout << "2. Insert at the end\n";
			cout << "3. Insert at a specific position\n";
			cout << "4. Delete from the beginning\n";
			cout << "5. Delete from the end\n";
			cout << "6. Delete from a specific position\n";
			cout << "7. Display the list\n";
			cout << "8. Exit\n";
			cout << "Enter your choice: ";
			cin >> choice;

			//  print using switch statement
			switch (choice) {
				case 1:
					cout << "Enter value to insert: ";
					cin >> value;
					csll.insertAtBeginning(value);
					break;
				case 2:
					cout << "Enter value to insert: ";
					cin >> value;
					csll.insertAtEnd(value);
					break;
				case 3:
					cout << "Enter value to insert: ";
					cin >> value;
					cout << "Enter position: ";
					cin >> position;
					csll.insertAtPosition(value, position);
					break;
				case 4:
					csll.deleteFromBeginning();
					break;
				case 5:
					csll.deleteFromEnd();
					break;
				case 6:
					cout << "Enter position to delete: ";
					cin >> position;
					csll.deleteFromPosition(position);
					break;
				case 7:
					csll.display();
					break;
				case 8:
					cout << "Exiting...\n";
					return 0;

				default:
					cout << "Invalid choice.Try again" << endl;
			}
		}
		return 0;
	}































































