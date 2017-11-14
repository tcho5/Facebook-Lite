#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include "FBLPostLL.h"
using namespace std;

FBLPostLL::FBLPostLL(){
	head = nullptr;
	tail = nullptr;
}

void FBLPostLL::thirdMenu(string first, string last, string userPost){
	string userInput, command, text;
	while(true){
		cout << "To Like the post, Enter: LIKE" << endl;
		cout << "To Comment the post, Enter: COMMENT" << endl;
		cout << "To display all comments in chronological order Enter: READ_AZ" << endl;
		cout << "To display all comments in reverse chronological order Enter: READ_ZA" << endl;
		cout << "To return, Enter: DONE" << endl;
		cout << "Enter a command: ";
		getline(cin, userInput);
		stringstream ss(userInput);
		ss>>command;
		getline(ss, text);
		cout << endl;
		if(command == "LIKE"){
			like(userPost);					
		}
		else if(command == "COMMENT"){
			createComment(first, last, text, userPost);
		}
		else if(command == "READ_AZ"){
			readAZ();
		}
		else if(command == "READ_ZA"){
			readZA();
		}
		else if(command == "DONE"){break;}
		else{cout << "Invalid Entry... Please try again." << endl;}

	}

}
void FBLPostLL::createComment(string first, string last, string text, string userPost){
	FBLPostLLNode *temp = new FBLPostLLNode;
	for(FBLPostLLNode *pos = head; pos != nullptr; pos = pos->next){
		string temp1 = pos->data.userPost;
		if(userPost == temp1){
			temp = pos;
			temp->data.comment->create(last,first,text);
			cout << "Commented!" << endl;
		}
	}
}
void FBLPostLL::readAZ(){
	FBLPostLLNode *temp = new FBLPostLLNode;
	temp = head;
	if(temp!=nullptr){
		temp->data.comment->readAZ();
		//cout << "Commented!" << endl;	
	} 
}
void FBLPostLL::readZA(){
	FBLPostLLNode *temp = new FBLPostLLNode;
	temp = head;
	if(temp!=nullptr){
		temp->data.comment->readZA();
	} 
}

void FBLPostLL::create(string post){//Make a create new post function inserts new node
	FBLPostLLNode *temp = new FBLPostLLNode;
	temp->data.setuserPost(post);
	//temp->data.ID.
	
	if(this->head == nullptr){//if head == NULL then linked list is empty so now add
		head = temp;
		tail = temp;
	}
	else{
		tail->next = temp;
		tail = temp;
	}
	temp = nullptr;
	delete temp;	
}
void FBLPostLL::create(string post, string userID){
	FBLPostLLNode *temp = new FBLPostLLNode;
	temp->data.setuserPost(post);
	//temp->data.setID(userID);
	//ID = userID;
	temp->data.ID = userID;
	//temp->data.ID.
	if(this->head == nullptr){//if head == NULL then linked list is empty so now add
		head = temp;
		tail = temp;
	}
	else{
		tail->next = temp;
		tail = temp;
	}
	temp = nullptr;
	delete temp;
}
void FBLPostLL::like(string userPost){
	//FBLPostLLNode *temp = new FBLPostLLNode;

	for(FBLPostLLNode *pos = head; pos != nullptr; pos = pos->next){
		string temp1 = pos->data.userPost;
		if(userPost == temp1){
			//temp = pos;
			pos->data.addLike();
			cout << "Post was liked!" << endl;	
		}
	}
}
void FBLPostLL::display(){
//Make a display function that reads first Post
	//If no post has been made, cout << "Nothing to READ"
	FBLPostLLNode *temp = new FBLPostLLNode;
	temp = head;
	if(temp!=nullptr) cout << endl << temp->data.getuserPost() << endl;
	else{
		cout << "Nothing to READ" << endl;
	}
}
string FBLPostLL::getFirstPost(){
	FBLPostLLNode *temp = new FBLPostLLNode;
	temp = head;
	if(temp!=nullptr) return temp->data.userPost;
		//getuserPost();
		//cout << endl << temp->data.getuserPost() << endl;
}
FBLPost FBLPostLL::getPost(string post){
	for(FBLPostLLNode *pos = head; pos != nullptr; pos = pos->next){
		string temp = pos->data.userPost;
		if(post == temp){
			return pos->data;
		}
	}
}
void FBLPostLL::displayWall(){
	FBLPostLLNode *temp = new FBLPostLLNode;
	temp = head;
	cout << endl;
	while(temp!=nullptr){
		cout << "Likes: " << temp->data.likes << " " << temp->data.getuserPost() << endl;
		temp = temp->next;
	}
}
void FBLPostLL::displayFeed(){
	FBLPostLLNode *temp = new FBLPostLLNode;
	temp = head;
	cout << endl;
	while(temp!=nullptr){
		cout << "Post: " << temp->data.getuserPost()<< endl;
		temp = temp->next;
	}
	
}

void FBLPostLL::deletePost(){//Make a delete function that deletes first Node
	FBLPostLLNode *temp = new FBLPostLLNode;
	temp = head;
	if(head!=nullptr)head = head->next; delete temp;
}
bool FBLPostLL::postChecker(){
	FBLPostLLNode *temp = new FBLPostLLNode;
	temp = head;
	if(head!=nullptr) return true; // Returns true if head is not null
	else{return false;} //Returns false if head is null;
}


