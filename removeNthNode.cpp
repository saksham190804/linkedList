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
	void reverse(){
		Node* curr=head;
		Node* prev=NULL;
		while(curr!=NULL){
			Node* nxt=curr->next;
			curr->next=prev;
			prev=curr;
			curr=nxt;
			
		}
		head=prev;
	}
	void remove(int idx){
		Node* temp=head;
		for(int i=0;i<idx-1;i++){
			temp=temp->next;
		}
		// reached idx-1 position
		temp->next=temp->next->next;
	}
		  
};

int main(){
	List ll;
	ll.push_front(5);
	ll.push_front(4);
	ll.push_front(3); // 4->5->3->null
	ll.print_ll();
	ll.push_back(6);
	ll.push_back(7);
	ll.print_ll(); // 4->5->3->5->4->null
	ll.reverse();
	ll.print_ll();
	ll.remove(2);
	ll.print_ll();
}