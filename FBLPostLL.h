#ifndef FBLPOSTLL_H
#define FBLPOSTLL_H
#include "FBLPost.h"
#include "FBLUser.h"

using namespace std;

class FBLUser;
class FBLPostLLNode{
	public:
		FBLPost data;
		FBLPostLLNode *next = nullptr;
};

class FBLPostLL{
	public:
		FBLPostLL();
		void create(string);
		void create(string, string);
		void createComment(string, string, string, string);
		void display();
		void displayWall();
		void displayFeed();
		void deletePost();
		void thirdMenu(string, string, string);
		bool postChecker();
		void like(string);
		void setID(string);
		void readAZ();
		void readZA();
		string getFirstPost();
		FBLPost getPost(string);
		//string ID;

	private:
		FBLPostLLNode *head, *tail;
		//FBLUser *userID;

};
#endif
