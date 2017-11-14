#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "FBLUserLL.h"
#include "FBLUser.h"

using namespace std;


FBLUserLL::FBLUserLL(){
	head = nullptr;
	tail = nullptr;
}

void FBLUserLL::create(string userID, string password, string first, string last){
	FBLUserLLNode *temp = new FBLUserLLNode;
	temp->data.setuserID(userID);
	temp->data.setpassword(password);		
	temp->data.setfirst(first);
	temp->data.setlast(last);

	if(head == nullptr){//if head == NULL then linked list is empty so now add
		head = temp;
		tail = temp;
	}else{
		tail->next = temp;
		tail = temp;
	}
	//temp = nullptr;
	//delete temp;
}
void FBLUserLL::addFriend(vector<FBLUser*> user, string userID){
	for(FBLUserLLNode *pos = head; pos != nullptr; pos = pos->next){
		string tempID = pos->data.getuserID();
		if(userID == tempID){

			pos->data.setfriends(user);	
		}
	}
	
}
bool FBLUserLL::checkuserID(string userID){ //returns true if user exists false otherwise	
	for(FBLUserLLNode *pos = head; pos != nullptr; pos = pos->next){
		string tempID = pos->data.getuserID();
		if(userID == tempID){
			return true; //User exist
		}
	}
	return false; 
}
bool FBLUserLL::checkpassword(string password){ //returns true if user exists false otherwise
	for(FBLUserLLNode *pos = head; pos != nullptr; pos = pos->next){
		string tempPW = pos->data.getpassword();
		if(password == tempPW){
			return true; //User exist
		}
	}
	return false; // User doesn't exist
}

FBLUser FBLUserLL::getFBLUser(string userID){//returns the correct FBLUser corresponding to ID
	for(FBLUserLLNode *pos = head; pos != nullptr; pos = pos->next){
		string tempID = pos->data.getuserID();
		if(userID == tempID){
			return pos->data;
		}
	}
}
void FBLUserLL::users(){
	for(FBLUserLLNode *pos = head; pos != nullptr; pos = pos->next){
		cout << pos->data.getlast() << ", " << pos->data.getfirst() << " <" << pos->data.getuserID() << ">" << endl; 
	}
}
void FBLUserLL::selectionSort(){
	if(head==nullptr) return;
	FBLUserLLNode *h = head, *i, *j;
	for(i = h; i->next!=nullptr; i = i->next){
		FBLUserLLNode *min;
		min = i;
		for(j = i->next; j!=nullptr; j=j->next){
            if(j->data.getlast() < min->data.getlast())
                min=j;
        }
        if(min!=i){

        	FBLUser temp1;
        	temp1 = min->data;
        	min->data = i->data;
        	i->data = temp1;
        }
        head = h;
	}
}
