
#include<iostream>// Problem 7Palindrome Check Singly Linked List
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
	Node * reverse(Node *ptr);
	bool IsPalindrome();
};
int main()
{
	LinkedList l;
	l.insert(4);
	l.insert(5);
	l.insert(6);
	l.insert(5);
	l.insert(4);
	cout << endl << "List is: ";
	l.display();
	if (l.IsPalindrome() == true)
		cout << endl << "It is Palindrome" << endl;
	else
		cout << endl << "It is not a Palindrome" << endl;
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
bool LinkedList::IsPalindrome() {
	Node *temp = head; int mid;
	if (length == 1)//if only one element,it is a palindrome
		return true;
	else {
		if (length % 2 == 0)
			mid = length / 2;
		else
			mid = (length + 1) / 2;
		for (int i = 1; i < mid; i++) //traversing till middle node
			temp = temp->next;
		Node *reversedHead = reverse(temp->next); //reversing after middle node to end

		while (head != NULL&&reversedHead != NULL) { //comparing two halfs of list
			if (head->data != reversedHead->data) //if element not equal ,return false
				return false;
			head = head->next;
			reversedHead = reversedHead->next;
		}
		return true;
	}
}
void LinkedList::display() {
	Node *temp; temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}


