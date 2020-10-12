
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
bool search(int n) {
Node *temp; temp = head;
while (temp != NULL) {
if (temp->data == n)
return true;
temp = temp->next;
}
return false; //if not found at all
}
};
int main()
{
LinkedList l1, l2; int number; char choice='n';
l1.insert(3);
l1.insert(4);
l1.insert(5);
l1.insert(6);
l1.display();
cout << endl;
do {
cout << "Enter number to find: ";
cin >> number;
if (l1.search(number) == true)
cout << "Number found!!" << endl;
else
cout << "Number not found!!" << endl;
cout << "Do you want to go again?(y/n) ";
cin >> choice;
} while (choice == 'y'||choice=='Y'); //to go again
system("pause");
return 0;
}
