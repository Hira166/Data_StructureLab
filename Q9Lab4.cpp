
#include<iostream>// Problem 9 Move Last to Front Singly Linked List
using namespace std;
struct Node {
public:
	int data;
	Node *next;
};
class LinkedList {
	int length;
public:
	Node *head, *tail;
	LinkedList();
	void insert(int n);
	void display();
	void moveLastToFront();
};
int main()
{
	LinkedList l;
	l.insert(4);
	l.insert(5);
	l.insert(6);
	l.insert(8);
	l.insert(9);
	cout << endl << "List is: ";
	l.display();
	l.moveLastToFront();
	cout << endl << "List is: ";
	l.display();
	cout << endl;
	system("pause");
	return 0;
}
LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
	length = 0;
}
void LinkedList::insert(int n) {
	Node *temp = new Node;
	temp->data = n; temp->next = NULL;
	if (head == NULL) {
		head = temp; tail = temp;
	}
	else { //inserting new node after current node
		tail->next = temp;
		tail = temp;
	}
	length++;
}
void LinkedList::moveLastToFront() {
	Node *temp; temp = head;//points to last node
	Node *prev; prev = head;//points to second last node
	if (head == NULL) //when only one node 
		return;
	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	temp->next = head; //last node now points to head
	head = temp;//head updated
	prev->next = NULL; //prev node is now last node
}
void LinkedList::display() {
	Node *temp; temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
