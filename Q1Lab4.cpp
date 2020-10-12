
#include<iostream> 
using namespace std;
struct Node {
public:
	int data;
	Node *next;
};
class LinkedList {
	Node *head, *tail;
	int length;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
		length = 0;
	}
	void insert(int x) {
		Node *temp = new Node;//temporary pointer
		temp->next = NULL; 
		if (head == temp) { //if both are pointing to NULL means it is one and only node
			temp->data = x;	//addition of first node
			temp->next = NULL;
		}
		else { //if adding after first node
			temp->data = x;
			temp->next = head;//updating temp
			head = temp; //now updating head i.e head now points to
		}
		length++; //keeping count of number of nodes
	}
	void deletion(int y) {
		Node *temp, *prev;
		temp = head; prev = head;
		while (temp->data != y) {
			prev = temp;
			temp = temp->next;
		}
		if (temp == head) {
			head = temp->next;
			free(temp);
		}
		else if (temp == tail) {
			prev->next = NULL;
			tail = prev;
			free(temp);
		}
		else {
			prev->next = temp->next;
			free(temp);
		}
		length--;
	}
	void display() {
		Node *temp;
		temp = head;
		cout << "Display is: ";
		while (temp != NULL) { 
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	bool SumCheck(int number) {
		int sum = 0;
		int origNum = number;
		while (number != 0) {
			sum = sum + number % 10;
			number = number / 10;
		}
		if (sum == 10)
			return true;
		return false;
	}
	void deleteSumTen() {
		Node *first = head;
		Node *temp;
		int y;
		while (first != NULL) {
			if (SumCheck(first->data) == true) {//if sum is 10
				temp = first;
				deletion(temp->data);
			}
			first = first->next;
		}
	}//function end
};
int main()
{
	LinkedList l1, l2; int number; char choice = 'n';
	l1.insert(3);
	l1.insert(41);
	l1.insert(73);
	l1.insert(6);
	l1.display();
	cout << endl;
	l1.deleteSumTen();
	l1.display();


	system("pause");
	return 0;
}