#include <iostream>
#include"Header.h"
#include <time.h>
#include <stdlib.h>
#include <string>

//#include <conio.h>
//#include <windows.h>
using namespace std;

int main(void)

{
	srand(time(0));
	Forum* oop; //create class forum

	int num_of_posts = 10;
	int num_of_threads = 20;
	int num = Randoms(0, 9);
	Thread* thread_ptr = NULL;

	oop = new Forum("Object Oriented Programming", num_of_threads, num_of_posts);//title/thread num/posts num
	oop->Print_thr_ttls1(); //print all thread titles




	//FOR BINARY TREE/TAKING THREAD POINTER _____________________________
	thread_ptr = oop->Find_thrd("Rules and usefull informations"); //find this thread
	if (thread_ptr != NULL)
	{
		cout << endl << "This is the tree part" << endl;
		cout << "______________________________" << endl;
		Tree_node* tree_head = new Tree_node("EMPTY");

		tree_head->Insert_thread(thread_ptr, num_of_posts);
		tree_head->print2DUtil(tree_head, 4);
		cout << endl;
		cout << "Printing InOrder"<<endl;

		tree_head->printInorder();
		cout << endl;

		//create second tree to test merge..........
		Thread* test = NULL;
		test = oop->Find_thrd("Welcome to DIT");
		if(test!=NULL)
		{
		Tree_node* tree_head2 = new Tree_node("EMPTY");
		tree_head2->Insert_thread(test, num_of_posts);
		//tree_head2->print2DUtil(tree_head2, 4);

		tree_head->Merge_tree(tree_head2); //.......merge

		tree_head->print2DUtil(tree_head, 4); //.......print
		cout << "Printing InOrder" << endl;
		tree_head->printInorder();//print

		cout << endl;
		tree_head2->delete_tree();
		}
		else
		cout << "!!!!!!!!!!______I did not find the thread please try again_____!!!!!"<<endl;
		tree_head->delete_tree();//....delete

		cout << "______________________________" << endl;
	}
	//else cout << "I can not find the thread you are looking for" << endl;




	//______________________________________________________


	cout << endl;
	cout << endl; cout << endl;
	cout << endl; cout << endl;
	cout << endl; cout << endl;
	cout << endl; cout << endl;
	cout << endl;
	int rnd_id = Randoms(1, (num_of_posts - 1));
	rnd_id = (rnd_id *num_of_threads) + 1000;

	oop->Find_post1(rnd_id); //find random post

	oop->Print_forum();
	oop->~Forum();








}
