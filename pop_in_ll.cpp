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
};

class List{
	Node *head;
	Node* tail;
public:
	List(){
		head=NULL;
		tail=NULL;
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
	void popFront(){
		Node* temp=head;
		head=head->next;
		
		temp->next = NULL;
		delete temp;
    }
    void popBack(){
    	Node* temp = head;
    	while (temp->next->next != NULL) {
        	temp = temp->next;
    	}
    	temp->next = NULL;
	}
		  
};

int main(){
	List ll;
	ll.push_front(3);
	ll.push_front(5);
	ll.push_front(4); // 4->5->3->null
	ll.print_ll();
	ll.push_back(5);
	ll.push_back(4);
	ll.print_ll(); // 4->5->3->5->4->null
	ll.popFront();
	ll.print_ll();
	ll.popBack();
	ll.print_ll();
}