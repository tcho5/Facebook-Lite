#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string.h>
#include "FBLUser.h"
#include "FBLUserLL.h"

FBLUser::FBLUser(){
	userID = "";
	password = "";
	first = "";
	last = "";
	//postLL = new FBLPostLL();
	feed = new FBLPostLL();
	wall = new FBLPostLL();
}

void FBLUser::setuserID(string input){
	userID = input;
}
string FBLUser::getuserID(){
	return userID;
}
void FBLUser::setpassword(string input){
	password = input;
}
string FBLUser::getpassword(){
	return password;
}
void FBLUser::setfirst(string input){
	first = input;
}
string FBLUser::getfirst(){
	return first;
}
void FBLUser::setlast(string input){
	last = input;
}
string FBLUser::getlast(){
	return last;
}
FBLPostLL FBLUser::getWall(){
	return *wall;
}
FBLPostLL FBLUser::getFeed(){
	return *feed;
}
vector<FBLUser*> FBLUser::getFriends(){
	return friends;
}
void FBLUser::setfriends(vector<FBLUser*> user){
	this->friends = user;
}

void FBLUser::trim(string &s){
	size_t p = s.find_first_not_of(" \t");
	s.erase(0, p);
	
	p = s.find_last_not_of(" \t");
	if (string::npos != p) s.erase(p+1);

}
void FBLUser::secondMenu(FBLUserLL *userLL){
	string userInput, command, text, buf, tempID;
	string testing;
	int argCounter;
	bool userChecker, postChecker, friendChecker = true;
	FBLUser *user = new FBLUser;

//MAYBE DELETE THAT AT THE END!	!!!
	while(true){
		cout << "To Logout, Enter: LOGOUT" << endl;
		cout << "To Post something, Enter: POST <Your Text>" << endl;
		cout << "To Read, Enter: READ" << endl;
		cout << "To Add a friend, Enter: FRIEND <userID>" << endl;
		cout << "To view your friends, Enter: MYFRIENDS" << endl;
		cout << "To view your feed, Enter: MYFEED" << endl;
		cout << "To view your wall, ENTER: MYWALL" << endl;
		cout << "Enter a command: ";

		getline(cin, userInput);
		stringstream ss(userInput);
		ss>>command;

		getline(ss, text);
		trim(text);

		if (command== "POST") {
			wall->create(text);
			for(vector<FBLUser*>::iterator it = friends.begin(); it != friends.end(); it++){
				FBLUser *temp;
			 	temp = *it;
				temp->feed->create(text, this->userID);
			}
		}
		else if(command == "READ"){
			feed->display();
			postChecker = feed->postChecker(); // true if head is not null
			if(postChecker == true){
				string userPost = feed->getFirstPost();
				string tempID = feed->getPost(feed->getFirstPost()).ID;
				//string tempID = userPost.ID;
				userLL->getFBLUser(tempID).wall->thirdMenu(this->first, this->last, userPost);
				feed->deletePost();

			}
			//if there is a post, then it will go to 3rd menu
		}
		else if(command =="FRIEND"){
			tempID = text;
			FBLUser *user = new FBLUser();	
			FBLUser *currentUser = new FBLUser();
			*user = userLL->getFBLUser(tempID);
			*currentUser = userLL->getFBLUser(userID);
			userChecker = userLL->checkuserID(tempID);

			vector<FBLUser*> userFriends = user->getFriends();

			if(userChecker == true){ //user does exist
				if(tempID != this->userID){
					for(vector<FBLUser*>::iterator it = friends.begin(); it != friends.end(); it++){
						FBLUser *temp;
			 			temp = *it;
			 			if(temp->userID == tempID) {
			 				friendChecker = false;
			 				break;
			 			}
			 		}
					if (friendChecker == true){
						friends.push_back(user);
						userFriends.push_back(currentUser);
						userLL->addFriend(friends, userID);
						userLL->addFriend(userFriends, tempID);
					}
					else{cout << "Cannot Add this User... " << endl;}						
				}
				else{cout << "Cannot Add this User... " << endl;}
			}			
		}
		else if(command == "MYFRIENDS"){
			for(vector<FBLUser*>::iterator it = friends.begin(); it != friends.end(); it++){
				FBLUser *temp;
			 	temp = *it;
				cout << temp->getfirst() << " " << temp->getlast() << endl;
			}
		}
		else if(command == "MYFEED"){
			feed->displayFeed();
		}
		else if(command == "MYWALL"){wall->displayWall();

		}
		else if(command == "LOGOUT") break;
		else{cout << endl << "Invalid Entry. Please Try Again..." << endl;}
		cout << endl;
	}
}

