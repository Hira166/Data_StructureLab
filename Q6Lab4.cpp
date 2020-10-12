
#include<iostream>// Problem 6 Reverse Print using Recursion
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
	void deletion(int d);
	void display();
	void reversePrint(Node *h);
};
int main()
{
	LinkedList l;
	l.insert(4);
	l.insert(5);
	l.insert(6);
	l.insert(8);
	l.insert(9);
	l.display();
	cout << endl << "Values in reverse order are: ";
	l.reversePrint(l.head);
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
void LinkedList::deletion(int d) {
	Node *temp, *prev;
	temp = head; prev = head;
	while (temp->data != d) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == head) {//from start/head
		head = temp->next;
		free(temp);
	}
	else if (temp == tail) {//from end/tail
		prev->next = NULL;
		tail = prev;
		free(temp);
	}
	else {//from inbetween(delete B) :A-B-C
		prev->next = temp->next; //A will now point to C, B gets deleted
	}
	length--;
}
void LinkedList::display() {
	Node *temp; temp = head;
	cout << endl << "Values are: ";
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
void LinkedList::reversePrint(Node *h) {
	if (h != NULL) { //base case
		reversePrint(h->next);
		cout << h->data << " ";
	}
}
