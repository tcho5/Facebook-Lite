#ifndef FBLUSERLL_H
#define FBLUSERLL_H
#include <string.h>
#include "FBLUser.h"
using namespace std;

class FBLUser;
class FBLUserLLNode{
	public: 
		FBLUser data;
		FBLUserLLNode *next = nullptr;
};

class FBLUserLL{
	public:
		FBLUserLL();
		void create(string, string, string, string);
		bool checkuserID(string);
		FBLUser getFBLUser(string);
		bool checkpassword(string);
		void addFriend(vector<FBLUser*> user, string);
		void users();
		void selectionSort();

	private:
		FBLUserLLNode *head, *tail;
};

#endif

