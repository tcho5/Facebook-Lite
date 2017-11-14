#include <iostream>
#include <stdlib.h>
#include "Comment.h"

using namespace std;

Comment::Comment(){
	last = "";
	first = "";
	text = "";
}
void Comment::setLast(string last){
	this->last = last;
}
string Comment::getLast(){
	return last;
}
void Comment::setFirst(string first){
	this->first = first;
}
string Comment::getFirst(){
	return first;
}
void Comment::setText(string text){
	this->text = text;
}
string Comment::getText(){
	return text;
}