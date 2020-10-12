
#include<iostream>// Problem 3 Swap Adjacent
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
	void SwapAdjacent();
};
int main()
{
	LinkedList l;
	l.insert(4);
	l.insert(5);
	l.insert(6);
	l.insert(8);
	l.insert(9);
	l.insert(2);
	cout << endl << "List is: ";
	l.display();
	l.SwapAdjacent();
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
void LinkedList::SwapAdjacent() {
	Node *temp; temp = head;
	while (temp != NULL && temp->next != NULL) {//traverse until second & last
		swap(temp->data, temp->next->data); //swap an element by its next
		temp = temp->next->next; //move 2 steps further
	}
}
void LinkedList::display() {
	Node *temp; temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
