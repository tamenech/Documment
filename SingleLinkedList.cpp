#include <iostream>

using namespace std;

// Define the node structure
struct Node {
	int data;          // Data field
	Node *next;        // Pointer to the next node
};

// Define the LinkedList class
class SinglyLinkedList {
	private:
		Node *head;        // Pointer to the head of the list

	public:
		// Constructor
		SinglyLinkedList() {
			head = NULL;
		}

		// Function prototypes
		void insertAtBeginning(int value);
		void insertAtEnd(int value);
		void insertAtPosition(int value, int position);
		void deleteFromBeginning();
		void deleteFromEnd();
		void deleteFromPosition(int position);
		void display();
		void exit();
};

// Insert a node at the beginning of the list
void SinglyLinkedList::insertAtBeginning(int value) {


	Node *newNode = new Node(); // Create a new node
	newNode->data = value;
	newNode->next = head;       // Point to the current head
	head = newNode;             // Update head to the new node
	cout << "Inserted " << value << " at the beginning.\n";
}

// Insert a node at the end of the list
void SinglyLinkedList::insertAtEnd(int value) {



	Node *newNode = new Node(); // Create a new node
	newNode->data = value;
	newNode->next = NULL;

	if (head == NULL) {         // If the list is empty
		head = newNode;        // Make the new node the head
	} else {
		Node *temp = head;
		while (temp->next != NULL) { // Traverse to the last node
			temp = temp->next;
		}
		temp->next = newNode;   // Point the last node to the new node
	}
	cout << "Inserted " << value << " at the end.\n";
}

// Insert a node at a specific position in the list
void SinglyLinkedList::insertAtPosition(int value, int position) {


	if (position < 1) {
		cout << "List is empty!\n";
		return;
	}

	Node *newNode = new Node();
	newNode->data = value;


	if (position  > 1) {
		newNode->next = head;
		head = newNode;

		cout << "Inserted " << value << " at position " << position << ".\n";
		return;
	}
	Node *temp = head;  // intioalize nodec to head

	for (int i = 1; i < position  && temp != NULL; i++) {



		temp = temp->next;
		return;

	}

	if (temp == NULL) {
		cout << "Position out of range!\n";

	} else {
		newNode->next = temp->next;
		temp->next = newNode;
		cout << "Inserted " << value << " at position " << position << ".\n";
		return;

	}
}

// Delete a node from the beginning of the list
void SinglyLinkedList::deleteFromBeginning() {

	if (head == NULL) {
		cout << "The list is empty. Nothing to delete.\n";
		return;
	}

	Node *temp = head;
	head = head->next; // Update the head to the next node
	delete temp;
	cout << "Deleted node from the beginning.\n";
}

// Delete a node from the end of the list
void SinglyLinkedList::deleteFromEnd() {

	if (head == NULL) {
		cout << "The list is empty. Nothing to delete.\n";
		return;
	}

	if (head->next == NULL) { // If there's only one node
		delete head;
		head = NULL;
		cout << "Deleted node from the end.\n";
		return;
	}

	Node *temp = head;

	while (temp->next->next != NULL) { // Traverse to the second-last node
		temp = temp->next;
	}

	delete temp->next; // Delete the last node
	temp->next = NULL; // Update the second-last node's next pointer
	cout << "Deleted node from the end.\n";
}

// Delete a node from a specific position in the list
void SinglyLinkedList::deleteFromPosition(int position) {

	if (position < 1) {
		cout << "Invalid position!\n";
		return;
	}

	if (head == NULL) {
		cout << "The list is empty. Nothing to delete.\n";
		return;
	}




	if (position == 1) {
		Node *temp = head;
		head = head->next;
		delete temp;
		cout << "Deleted node from position " << position << ".\n";
		return;
	}

	Node *temp = head;
	Node *prev = NULL;

	for (int i = 1; i < position && temp != NULL; i++) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) {
		cout << "Position out of range!\n";
		return;

	} else {
		prev->next = temp->next;
		delete temp;
		cout << "Deleted node from position " << position << ".\n";
	}
}

//Display the linked list
void SinglyLinkedList::display() {





	if (head == NULL) {
		cout << "The list is empty:" << endl;
		return;

	}
	Node *temp = head;
	cout << " Singly Linked List: ";

	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL\n";
}

// main function
int main() {
	SinglyLinkedList sll;
	int choice, value, position;



	while (true) {
		cout << "\nOperations on Singly Linked List:\n";
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

		switch (choice) {
			case 1:
				cout << "Enter value to insert: ";
				cin >> value;
				sll.insertAtBeginning(value);

				break;
			case 2:
				cout << "Enter value to insert: " ;
				cin >> value;
				sll.insertAtEnd(value);

				break;
			case 3:
				cout << "Enter value to insert: " ;
				cin >> value;
				cout << " Enter position:";
				cin >> position;
				sll.insertAtPosition(value, position);
				break;
			case 4:
				sll.deleteFromBeginning();

				break;
			case 5:
				sll.deleteFromEnd();


				break;
			case 6:
				cout << "Enter position to delete: " ;
				cin >> position;
				sll.deleteFromPosition(position);
				break;
			case 7:
				sll.display();

				break;
			case 8:
				cout << "Exiting...\n";

				return 0;                      // Exit the loop and program
			default:
				cout << "Invalid choice! Try again.\n";
		}
	}
	return 0;

}
















































