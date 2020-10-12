
#include<iostream> //Problem 10 Merge Two Lists
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
Node *ptr = new Node;
ptr->data = x; ptr->next = NULL;
if (head == NULL) { //when only 1 node
head = ptr; tail = ptr;
}
else {
tail->next = ptr;
tail = ptr;
}
length++;
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
cout << "Ascending Ordered Display is: ";
while (temp != NULL) { 
cout << temp->data << " ";
temp = temp->next;
}
}
void merge(LinkedList li2) {
if (li2.head == NULL ) //if second list is empty ,no merge needed
{
cout << "No merge needed as second list is empty"<<endl;
return;
}
else if (this->head == NULL) { //if first list is empty,
cout << "First list was empty!!" << endl;
this->head = li2.head;
this->tail = li2.tail;
}
else //if 2nd list is not empty ,then merge
{
this->tail->next = li2.head;
this->tail = li2.tail;
}
}
void BubbleSort() {
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
};
int main()
{
LinkedList l1, l2;
l1.insert(3);
l1.insert(5);
l1.insert(4);
l1.insert(6);
l1.BubbleSort();
l1.display();
cout << endl;
l2.insert(6);
l2.insert(8);
l2.insert(7);
l2.BubbleSort();
l2.display();
cout << endl;
l1.merge(l2);
l1.BubbleSort();
l1.display();
cout << endl;
system("pause");
return 0;
}
