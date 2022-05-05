#include <iostream>
#include <stdexcept>
using namespace std;
struct Node{
	int value; 
	Node *next;

	Node(int _value):
		value(_value), 
		next(nullptr)
	{}
};
int main(){
	Node *head=nullptr;
	for (int i=100; i>0;i--){
		Node *tmp=new Node(i);
		tmp->next=head;
		head=tmp;
	}
	Node *tmp=head;
	while (tmp !=nullptr){
		cout<<tmp->value<<", ";
		tmp= tmp -> next;
	}
	cout<<endl;

	if (head!= nullptr){
		Node *tmp=head;
		head=head->next;
		delete tmp;
	}
	while (head!=nullptr){
		Node *tmp=head;
		head=head->next;
		delete tmp;
	}
}
