#include <iostream>
#include <stdlib.h>
#include "FBLPost.h"

FBLPost::FBLPost(){
	userPost = "";
	likes = 0;
	comment = new CommentLL();
}

void FBLPost::setuserPost(string post){
	userPost = post;
}	
string FBLPost::getuserPost(){
	return userPost;
}
string FBLPost::getuserID(){
	return ID;
}
void FBLPost::addLike(){
	likes++;
}
