#include <iostream>
#include <stdexcept>

using namespace std;
struct Node {
	int value;
	Node *next;

	Node(int _value, Node *_next=nullptr):
		value(_value), 
		next(_next){}
};
class Stack{
	Node *head;
	public :
	Stack():head(nullptr){};
	void push(int x){
		//Node *tmp=new Node(x);
		head =new Node(x, head);
	}
	bool empty() const{
		return head==nullptr;
	}
	int top() const{
		if(empty()){
			throw std::runtime_error("top on an emty stack");
		}
		return head->value;
	}

	void pop(){
		if (empty()){
			throw runtime_error("pop on an empty stack");
		}
		pop_unsafe();
	}

	void clear(){
		while (!empty())
			pop_unsafe();
	}
	~Stack(){
		clear();
	} 

	Stack(const Stack& original):head(nullptr){
		if(!original.empty()){
			//copy the first value from original if it exists 
			head= new Node(original.head->value);

			Node *src= original.head->next;
			Node *dst=head;

			while(src!=nullptr){
				dst->next=new Node(src->value);

				dst= dst->next;
				src=src->next;
			}
		}
	}
	private:
	void pop_unsafe(){
		Node *tmp=head;
		head=head->next;
		delete tmp;
	}
};
int main(){

Stack Node;
Node.push(1);
Node.push(2);
Node.push(3);
Node.pop();

cout<<Node.top()<<endl;
Node.push(4);
cout<<Node.top()<<endl;




}
