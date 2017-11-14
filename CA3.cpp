#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "FBLUserLL.h"
using namespace std;

void topMenu(FBLUserLL *userLL){
	string userInput, command, buf;
	int argCounter;
	bool userChecker; //return true if exists false if doesnt
	bool pwChecker;
	//vector<string> argVector; 
	while(true){
		cout << "To create a new user, Enter: CREATE userID password FirstName LastName" << endl;
		cout << "To Login, Enter: LOGIN userID password" << endl;
		cout << "To View all Users, Enter: USERS" << endl;
		cout << "To sort the Users, Enter SORTUSERS" << endl;
		cout << "TO Quit, Enter: QUIT " << endl;
		cout << "Enter a command: ";

		getline(cin, userInput);
		stringstream ss(userInput);
		vector<string> argVector; //Create vector to hold words.
		while(ss >> buf) argVector.push_back(buf);
		command = argVector[0];
		argCounter = argVector.size(); 
		cout << endl;

		if(command == "CREATE" && argCounter == 5){
			if(userLL == nullptr){cout << "Hello";}
			userChecker = userLL->checkuserID(argVector[1]);
			if(userChecker == false){ //User doesn't exist
				userLL->create(argVector[1],argVector[2],argVector[3],argVector[4]);
			}
			else{cout << "User Already Exist!" << endl;}
		}
		else if(command == "USERS"){
			userLL->users();
		}
		else if(command == "SORTUSERS"){
			userLL->selectionSort();
		}
		else if(command == "LOGIN" && argCounter == 3){
			userChecker = userLL->checkuserID(argVector[1]);
			pwChecker = userLL->checkpassword(argVector[2]);
			if(userChecker == true && pwChecker == true){ //user exists
				userLL->getFBLUser(argVector[1]).secondMenu(userLL);
			}
			else{cout << "User Does Not Exist!" << endl;}
		}
		else if (command == "QUIT" && argCounter == 1) break;
		else {cout << endl << "Invalid Entry. Please Try Again...";}
		cout << endl;
	}
}
int main(int argc, char *argv[]){
	FBLUserLL *userLL = new FBLUserLL();
	cout << endl;
	topMenu(userLL);

	delete userLL;
	userLL = nullptr;
	return 0;
}

