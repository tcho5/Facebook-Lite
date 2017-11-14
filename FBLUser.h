#ifndef FBLUSER_H
#define FBLUSER_H
#include <string>
#include <vector>
//#include "FBLUserLL.h"
#include "FBLPostLL.h"
using namespace std;

class FBLUserLL;
class FBLPostLL;
class FBLUser{
	public:
		FBLUser();
		void setuserID(string);
		string getuserID();
		void setpassword(string);
		string getpassword();
		void setfirst(string);
		string getfirst();
		void setlast(string);
		string getlast();
		//FBLPostLL getFBLPostLL();
		FBLPostLL getWall();
		FBLPostLL getFeed();
		void secondMenu(FBLUserLL*);
		void trim(string&);
		vector<FBLUser*> getFriends();
		void setfriends(vector<FBLUser*>);
		FBLPostLL *feed, *wall;
		string userID, password, first, last;
	private:
		//string userID, password, first, last;
		FBLPostLL *postLL;
		//FBLPostLL *feed, *wall;
		vector<FBLUser*> friends;
		//FBLUser *user = nullptr;

};
#endif
