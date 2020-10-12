
#include<iostream>// Problem 5 Group All Odd Together
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
	void GroupOddTogether();
};
int main()
{
	LinkedList l;
	l.insert(4);
	l.insert(5);
	l.insert(6);
	l.insert(8);
	l.insert(9);
	l.insert(3);
	cout << endl << "List is: ";
	l.display();
	l.GroupOddTogether();
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
void LinkedList::GroupOddTogether() {
	Node *temp; temp = head;
	Node *current; current = head;
	if (head == NULL) //if only one element ,no need to move
		return;
	else if (length == 2) //if only two elements ,no change needed.
		return;
	else { //when more than two elements
		while (temp != NULL) {
			if (temp->data % 2 != 0) { //if value is odd
				swap(temp->data, current->data); //swap value with head 
				current = current->next;//update head
			}
			temp = temp->next;
		}
	}
}
void LinkedList::display() {
	Node *temp; temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
