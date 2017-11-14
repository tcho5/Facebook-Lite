#
# Specifiy the target
all:	CA3

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
CA3:	CA3.o
	g++  FBLUserLL.o CA3.o FBLPostLL.o FBLUser.o FBLPost.o Comment.o CommentLL.o -o FBL -g


# Specify how the object files should be created from source files
CA3.o:	CA3.cpp FBLUser.h FBLUser.cpp FBLUserLL.h FBLUserLL.cpp FBLPost.h FBLPost.cpp FBLPostLL.h FBLPostLL.cpp CommentLL.cpp CommentLL.h Comment.cpp Comment.h

	g++ -c CA3.cpp -g
	g++ -c FBLUserLL.cpp -g
	g++ -c FBLPostLL.cpp -g
	g++ -c FBLPost.cpp -g
	g++ -c FBLUser.cpp -g
	g++ -c Comment.cpp 
	g++ -c CommentLL.cpp
	

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o FBL

