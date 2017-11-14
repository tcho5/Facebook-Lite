#include <iostream>
#include <stdlib.h>
#include "CommentLL.h"

using namespace std;

CommentLL::CommentLL(){
	head = nullptr;
	tail = nullptr;
}
void CommentLL::create(string last, string first, string text){
	CommentLLNode *temp = new CommentLLNode;
	temp->data.setLast(last);
	temp->data.setFirst(first);
	temp->data.setText(text);
	
	if(this->head == nullptr){//if head == NULL then linked list is empty so now add
		head = temp;
		tail = temp;
	}
	else{
		tail->next = temp;
		//head->next = temp;
		temp->prev = tail;
		tail = temp;

	}
	temp = nullptr;
	delete temp;
}
void CommentLL::readAZ(){
	for(CommentLLNode *pos = head; pos != nullptr; pos = pos->next){
		cout << pos->data.getFirst() << " " << pos->data.getLast() << ": " << pos->data.getText() << endl;
	}

}
void CommentLL::readZA(){
	for(CommentLLNode *pos = tail; pos != nullptr; pos = pos->prev){
		cout << pos->data.getFirst() << " " << pos->data.getLast() << ": " << pos->data.getText() << endl;
	}
}
void CommentLL::displayAll(){
	CommentLLNode *temp = new CommentLLNode;
	temp = head;
	cout << endl;
	cout << "       Comments: " << endl;
	while(temp!=nullptr){
		cout << "         ";
		cout << temp->data.getFirst() << " " << temp->data.getLast() << ": " << temp->data.getText() << endl;
			//cout << pos->data.comment->
		temp = temp->next;
	}
}


