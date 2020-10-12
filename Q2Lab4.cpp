
#include<iostream>// Problem 2 Bubble Sort & Selection sort
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
	void SelectionSort();
	void BubbleSort();
};
int main()
{
	LinkedList l, l1;
	l.insert(4);
	l.insert(5);
	l.insert(6);
	l.insert(8);
	l.insert(9);
	l.insert(3);
	cout << endl << "List is: ";
	l.display();
	l.BubbleSort();
	cout << endl << "Bubble Sorted List is: ";
	l.display();
	l1.insert(6);
	l1.insert(5);
	l1.insert(3);
	l1.insert(8);
	l1.insert(7);
	cout << endl << "List is: ";
	l1.display();
	l1.SelectionSort();
	cout << endl << "Selection Sorted List is: ";
	l1.display();
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
void LinkedList::SelectionSort() {
	Node *minimum;
	Node *first = head;
	Node *second;
	while (first->next != NULL) {
		minimum = first;//consider the first element as minimum
		second = first->next;
		while (second != NULL) {//now compare this minimum with each value
			if (minimum->data > second->data)
				minimum = second; //update minimum with new smallest value
			second = second->next;
		}
		swap(first->data, minimum->data);
		first = first->next;
	}
}
void LinkedList::BubbleSort() {
	Node *first; first = head;
	Node *second;
	while (first->next != NULL) {//till last
		second = first->next;
		while (second != NULL) { //move till second last element 
			if (first->data > second->data) { //comparing two adjacent values
				swap(first->data, second->data);
			}
			second = second->next;
		}
		first = first->next;
	}
}
void LinkedList::display() {
	Node *temp; temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}
