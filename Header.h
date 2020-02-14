#include <string>
using namespace std;
typedef struct date
{
	int day;
	int month;
	int year;
}date;



//////////////////////////////////////////////////////////////
//////////////_______POST_________/////////////////////////
class Post
{
private:
	string post_creator;
	string post_title;
	int post_id;
	date post_date;
	string text;

public:
	Post(/*string crt, string tlt, int id, date d, string txt*/);
	~Post();
	void Find_post3(int);
	string Get_post_name();
	string Get_post_theme();

};

//////////////////////////////////////////////////////////////
//////////////_______THREAD_________/////////////////////////
class Thread
{
private:
	string thread_creator;
	string theme;
	date thr_date;
	int posts_count;
	Post* post_arr;


public:
	Thread();
	~Thread();

	void Print_thr_ttls2();
	int Find_thrd2(string);
	void Set_posts_num(int);
	void Create_Posts();
	void Find_post2(int);
	void test();
	Post* return_post_array();
};

////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////_____FORUM______//////////////////////////
class Forum
{
private:

	int threads_count;
	string mytitle;
	Thread* threads_arr;
	
	

public:

	//Create_thrs_data_forum(string, string, date, int);
	Forum(string m,int count,int);
	~Forum();

	void Print_thr_ttls1();
	Thread* Find_thrd(string);//, Thread*);
	void Find_post1(int);
	void Print_forum();
};

////////////////////////////////////////////////////////////////////////////
class List_node
{
private:
	Post* list_post_ptr;
	List_node* next_node;

public:
	List_node(Post*);
	~List_node();
	void Insert_to_list(Post*);
	void delete_list();
	void print_list();
	void Insert_list_to_list(List_node*);
};



////////////////////////////////////////////////////////////////////////////
//_________________________TREE_______________________________________
class Tree_node
{
private:
	string Creator_name;
	List_node* list_ptr;
	Tree_node* left;
	Tree_node* right;



public:

	 Tree_node(string);
	 ~Tree_node();

	 void Insert_thread(Thread*,int);
	 void Insert_post(Post*);
	 void Insert_tree_node(Tree_node*);
	
	 void print2DUtil(Tree_node* root, int space);
	 void printInorder();
	 void delete_tree();
	 void Merge_tree(Tree_node*);

};


//////////////////////////////////////////////////////////////

int Randoms(int l, int u);


