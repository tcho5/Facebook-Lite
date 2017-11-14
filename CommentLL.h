#include "Comment.h"

using namespace std;

class CommentLLNode{
	public:
		Comment data;
		CommentLLNode *next = nullptr;
		CommentLLNode *prev = nullptr;
};
class CommentLL{
	public:
		CommentLL();
		void create(string, string, string);
		void displayAll();
		void readAZ();
		void readZA();

	private:
		CommentLLNode *head, *tail;
};
