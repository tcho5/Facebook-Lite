#ifndef FBLPOST_H
#define FBLPOST_H
#include "CommentLL.h"
using namespace std;


class FBLPost{
	public:
		FBLPost();
		void setuserPost(string);
		string getuserPost();
		string getuserID();
		void addLike();
		string userPost;
		string ID;
		int likes;
		CommentLL *comment;
	private:
		//string userPost;
		//CommentLL *comment;
		//int likes;


};

#endif
