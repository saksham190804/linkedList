#include <iostream>
using namespace std;

class Node{
public:	
	int data;
	Node* next;
	Node(int val){
		data=val;
		next=NULL;
	}
	~Node(){
		if(next!=NULL){
			cout<<"~Node"<<data<<endl;
			delete next;
			next=NULL;
		}
	}	
};

class List{
	Node *head;
	Node* tail;
public:
	List(){
		head=NULL;
		tail=NULL;
	}
	~List(){
		if(head!=NULL){
			cout<<"list destructor"<<endl;
			delete head;
			head=NULL;
		}
	}
	void push_front(int val){
		Node* newNode=new Node(val);
		if(head==NULL){
			head=tail=newNode;
		} else{
			newNode->next=head;
			head=newNode;
		}
	}
	
	void push_back(int val){
		Node* newNode=new Node(val);
		if(head==NULL){
			head=tail=newNode;
		} else{
			tail->next=newNode;
			tail=newNode;
		}
	}
	
	void print_ll(){
		Node* temp= head;
		while(temp!=NULL){
			if(temp->next==NULL){
				cout<<temp->data<<"->null"<<endl;
				break;
			}
			
			cout<<temp->data<<"->";
			temp=temp->next;
			
		}
	}
		  
};

int main(){
	List ll;
	ll.push_front(3);
	ll.push_front(5);
	ll.push_front(4); // 4->5->3->null
	ll.print_ll();
}