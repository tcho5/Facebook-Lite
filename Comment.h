#ifndef COMMENTLL_H
#define COMMENTLL_H

using namespace std;

class Comment{
	public:
		Comment();
		void setLast(string);
		string getLast();
		void setFirst(string);
		string getFirst();
		void setText(string);
		string getText();

	private:
		string last, first, text;

};



#endif