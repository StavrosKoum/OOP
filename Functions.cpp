#include"Header.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
//for sleep
//#include <conio.h>
//#include <windows.h>
#define COUNT 10
using std::cout;
using std::endl;
//using std::endl;

int postid =1001;

string thr_themes[] =
{
	"Welcome to DIT",
	"Welcome to DIT",
	"Welcome to DIT",
	"Welcome to DIT",
	"Welcome to DIT",
	"Rules and usefull informations",
	"Rules and usefull informations",
	"Rules and usefull informations",
	"Rules and usefull informations",
	"Rules and usefull informations"

};

string post_titles[] =
{
	"Random post name1",
	"Random post name2",
	"Random post name3",
	"Random post name4",
	"Random post name5",
	"Random post name6",
	"Random post name7",
	"Random post name8",
	"Random post name9",
	"Random post name10",
	"Random post name11",
	"Random post name12",
	"Random post name13",
	"Random post name14",
	"Random post name15",
	"Random post name16"
};

string post_txt[]
{
	"Random post txt1",
	"Random post txt2",
	"Random post txt3",
	"Random post txt4",
	"Random post txt5",
	"Random post txt6",
	"Random post txt7",
	"Random post txt8",
	"Random post txt9",
	"Random post txt10",
	"Random post txt11",
	"Random post txt12",
	"Random post txt13",
	"Random post txt14",
	"Random post txt15",
	"Random post txt16"
};

string names[]
{
	"Stavros",
	"Lakis Lalakis",
	"Ioannic",
	"Kostas",
	"Aris",
	"Alexandros",
	"Spyros",
	"Maria",
	"Eirini",
	"Alexia",
	"Katerina",
	"Nikos",
	"Kostas Mitroglou",
	"Markos",
	"Mitsos",
	"Paraskeuas",
	"John Cena",
	"Takis",

};

using namespace std;

int Randoms(int lower, int upper)
{
	//srand(time(0));
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;

}


//_____________________FORUM FUNCTIONS______________________________

Forum::Forum(string m, int num_of_thr, int num_of_posts)
{
	mytitle.insert(0, m);
	cout << "Forum with title : " << this->mytitle << " has just been created!" << endl;
	this->threads_count = num_of_thr;


	//---------threads-------------
	threads_arr = new Thread[num_of_thr]; //create a thread array
	for (int i = 0; i < threads_count; i++) //give them post number
	{
		threads_arr[i].Set_posts_num(num_of_posts);
		threads_arr[i].Create_Posts();
	}

}


void Forum:: Print_thr_ttls1()
{
	cout << endl << endl << "Printing all threads titles" << endl;
	for (int i = 0; i < threads_count; i++)
	{
		threads_arr[i].Print_thr_ttls2();
	}
}

Thread* Forum::Find_thrd(string t)//,Thread*ptr)
{
	int flag = 0;
	for (int i = 0; i < threads_count; i++) //search all threads
	{
		flag = threads_arr[i].Find_thrd2(t);
		if (flag == 1)
		{
			//cout << "FOUND IT!!!!!!!!!!!!!!!!!" << endl;
			//ptr = threads_arr;
			return &threads_arr[i];

		}
	}
	return NULL;
}

void Forum::Find_post1(int id)
{
	for (int i = 0; i < threads_count; i++) //search all threads
	{
		threads_arr[i].Find_post2(id);
	}
}

Forum::~Forum()
{
	cout << endl << endl << endl;
	delete[] &threads_arr[0];

	cout << "Forum with title : " << this->mytitle;
	cout << " is about to be destroyed" << endl;

}

void Forum::Print_forum()
{
	cout << "Forum has title: " << mytitle << " and it has " << threads_count << " threads" << endl;
}




//
//_____________________THREAD FUNCTIONS____________________________

Thread::Thread(/*string crt, string thm,date k,int count*/)
{
	//Sleep(1000);
	//srand(time(0));
	date cur_date;
	cur_date.day = 4;
	cur_date.month = 4;
	cur_date.year = 1998;

	string crt = "Stavros";

	//this->posts_count = count;
	this->thr_date = cur_date; //pass date
	thread_creator.insert(0, crt);//pass creator
	int num = Randoms(0, 9);
	theme.insert(0, thr_themes[num]);//pass theme*/
	cout << "Thread with subject :" << this->theme << " has been created!" << endl;

}



void Thread::Create_Posts()
{
	post_arr = new Post[this->posts_count];//create post array
}

Thread::~Thread()
{


	delete[] &post_arr[0];

	cout << "Thread with subject :" << this->theme << " is about to be destroyed!" << endl;
}



void Thread::Print_thr_ttls2()
{
	cout << this->theme << endl;
}

int Thread::Find_thrd2(string f)
{
	if (!(this->theme.compare(f)))
	{
		cout << endl << endl;
		cout << "I found the thread with theme : " << this->theme << endl;
		cout << "Creator: " << thread_creator << endl;
		cout << "Date: " << thr_date.day << "/" << thr_date.month << "/" << thr_date.year << endl;
		cout << "Number of Posts: " << posts_count << endl;
		return 1;
	}
	return 0;
}

void Thread::Set_posts_num(int num)
{
	this->posts_count = num;
}



void Thread::Find_post2(int id)
{
	for (int i = 0; i < posts_count; i++) //search all threads
	{
		post_arr[i].Find_post3(id);
	}
}

void Thread::test()
{
	cout << "------------" << theme << endl;
}


Post* Thread::return_post_array()
{
	return post_arr;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++






//_____________________POST FUNCTIONS____________________________

Post::Post(/*string crt, string tlt, int id,date d,string txt*/)
{
	date cur_date;
	cur_date.day = 4;
	cur_date.month = 4;
	cur_date.year = 1998;

	int chs = Randoms(0, 15);
	this->text.insert(0, post_txt[chs]);//pass the text
	post_title.insert(0, post_titles[chs]);//pass title

	this->post_date = cur_date; //pass date
	int rnd = Randoms(0,17);
	post_creator.insert(0, names[rnd]);//pass creatorn name

	this->post_id = postid;
	postid++; //add to id so the next wont be the same
	cout << "Post with title: " << this->post_creator<< " has been created!" << endl;

}

Post::~Post()
{

	cout << "Post number: " << post_id << " is about to be destroyed" << endl;
}


void Post::Find_post3(int id)
{
	if (this->post_id == id)
	{
		cout << endl << endl;
		cout << "I fount the post you were looking for" << endl;
		cout << "Creator is: " << post_creator << endl;
		cout << "Post title is: " << post_title << endl;
		cout << "Post id is: " << post_id << endl;
		cout << "Post created: " << post_date.day << "/" << post_date.month << "/" << post_date.year << endl;

	}
}

string Post::Get_post_name()
{
	return post_creator;
}

string Post::Get_post_theme()
{
	return this->post_title;
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////_____________TREE____//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
Tree_node::Tree_node(string name)
{
	Creator_name.insert(0, name);
	left = NULL;
	right = NULL;

	cout << " I made a tree node" << endl;
}

Tree_node:: ~Tree_node()
{
	cout << " I deleted a tree node" << endl;
}

void Tree_node::Insert_thread(Thread* thr,int num_of_posts)
{
	Post* post_ptr; //pointer to post array
	post_ptr = thr->return_post_array(); //I HAVE THE POST ARRAY!

	//loop to take all posts from the array
	for (int i = 0; i < num_of_posts; i++)
	{
		//CALL INSERT POST HERE(post_ptr+i)
		Insert_post(post_ptr);//insert post to this node,if not it will go to next
		post_ptr = post_ptr + 1; //get next post
	}



}



void Tree_node::Insert_post(Post* post_ptr)
{
	string name;
	name = post_ptr->Get_post_name();// get the  name.............!!!!!!!!

	if (!Creator_name.compare("EMPTY")) //if this is the first node
	{
		this->Creator_name.clear();
		this->Creator_name.insert(0, name);
		this->list_ptr = new List_node(post_ptr);

	}
	else
	{
		int r_l = Creator_name.compare(name);//see if you go left or right
		if (r_l < 0)
		{
			//go left
			// if null
			if (left == NULL)
			{
				//create node
				left = new Tree_node(name);
				left->list_ptr = new List_node(post_ptr);

			}
			else
			{
				//call insert post with left pointer to node
				left->Insert_post(post_ptr);
			}
		}
		else if(r_l > 0) //if going right
		{
			if (right == NULL)
			{
				//create node
				right = new Tree_node(name);
				right->list_ptr = new List_node(post_ptr);
			}
			else
			{
				//call insert post with left pointer to node
				right->Insert_post(post_ptr);
			}
		}
		else if (r_l == 0)
		{
			//ADD TO EXISTING LIST
			//Ttake list and put in in insert function (list fun)
			list_ptr->Insert_to_list(post_ptr);
			return;
		}
	}
}

void Tree_node::printInorder()
{
	//if (node == NULL)
	//	return;

	/* first recur on left child */
	if(left!=NULL)
	left->printInorder();

	/* then print the data of node */
	cout << Creator_name << " with posts: ";
	list_ptr->print_list();

	/* now recur on right child */
	if (right != NULL)
	right->printInorder();
}

void Tree_node::delete_tree()
{
	if (left != NULL)
		left->delete_tree();

	if (right != NULL)
		right->delete_tree();

	//delete this list
	this->list_ptr->delete_list();
	this->~Tree_node();

}





void Tree_node::Merge_tree(Tree_node* tree_node2)
{
	Insert_tree_node(tree_node2);
	if (tree_node2->left != NULL)
		Merge_tree(tree_node2->left);
	if (tree_node2->right != NULL)
		Merge_tree(tree_node2->right);
}

void Tree_node::Insert_tree_node(Tree_node* tree_node2)
{

	int r_l = this->Creator_name.compare(tree_node2->Creator_name);
	if (r_l < 0)
	{
		//go left
		// if null
		if (left == NULL)
		{
			left = new Tree_node(tree_node2->Creator_name);
			left->list_ptr = tree_node2->list_ptr;

		}
		else
		{
			left->Insert_tree_node(tree_node2);
		}
	}
	else if (r_l > 0) //if going right
	{
		if (right == NULL)
		{
			right = new Tree_node(tree_node2->Creator_name);
			right->list_ptr = tree_node2->list_ptr;

		}
		else
		{
			right->Insert_tree_node(tree_node2);
		}
	}
	else if (r_l == 0)
	{
		//insert post list to existing post list
		this->list_ptr->Insert_list_to_list(tree_node2->list_ptr);
	}
}



//________________________________________________________________________________
//_____________________________________LIST_____________________________________
List_node::List_node(Post* post)
{
	list_post_ptr = post;
	next_node = NULL;
	cout << "I just constructed a List node" << endl;
}

List_node::~List_node()
{
	cout << "I just deleted a List node" << endl;
}

void List_node::Insert_to_list(Post* post_ptr)
{
	if (next_node != NULL)
	{
		next_node->Insert_to_list(post_ptr);
	}
	else
	{
		next_node = new List_node(post_ptr);;
	}

}


void List_node::Insert_list_to_list(List_node* list2)
{
	if (next_node != NULL)
	{
		next_node->Insert_list_to_list(list2);
	}
	else
	{
		next_node = list2;
	}

}

void List_node::delete_list()
{
	if (next_node != NULL)
	next_node->delete_list();
	this->~List_node();
}

void List_node::print_list()
{
	string theme = list_post_ptr->Get_post_theme();
	cout <<  theme << endl;

	if (next_node != NULL)
		next_node->print_list();
}



void Tree_node::print2DUtil(Tree_node* root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->right, space);

	// Print current node after space
	// count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->Creator_name << "\n";

	// Process left child
	print2DUtil(root->left, space);
}
