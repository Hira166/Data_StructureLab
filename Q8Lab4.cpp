
#include<iostream>// Problem 8 Reverse Singly Linked List
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
	void display(Node *h);
	Node * reverse(Node *ptr);
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
	l.display(l.head);
	cout << endl << "Reversed linked list is: ";
	Node *reversedHead = l.reverse(l.head);
	l.display(reversedHead);
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
Node* LinkedList::reverse(Node *mid) {
	Node *tempNode = mid; //middle node
	Node *prevNode = NULL; //node before middle
	Node *nextNode = NULL;//node after middle
	while (mid != NULL) {//traverse till end of list
		nextNode = mid->next;
		mid->next = prevNode;
		prevNode = mid;
		mid = nextNode;
	}
	return prevNode;
}
void LinkedList::display(Node *h) {
	Node *temp; temp = h;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

