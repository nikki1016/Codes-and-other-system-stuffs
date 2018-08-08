#include <bits/stdc++.h>
using namespace std;

struct keyword_tree {
	bool isleaf; 				   //isleaf will be set if current state is end of a keyword
	struct keyword_tree *next[26]; //assuming keyword contain on lowercase letters
};

//Allocate memory for a state (node)
struct keyword_tree *create_state()
{
	struct keyword_tree *tmp;
	tmp = (struct keyword_tree*) malloc(sizeof(keyword_tree));
	if( !tmp ) return tmp;

	tmp->isleaf = false;
	for(int i = 0 ; i < 26; i++)
		tmp->next[i] = NULL;

	return tmp;
}

string keyword[] = {
	"/begin",
	"/end",
	"enumerate",
	"justify",
	"/item",
	"/includegraphics",
	"width",
	"height",
	"document",
	"figure",
};

string strng[] = {
	"begin",
	"end",
	"item",
	"includegraphics",
};

string other[] = {
  	"{",
	"}",
};

//Make a nodes(states) for a keyword ( if necessary)
void make_node(string word, struct keyword_tree * roott)
{
	struct keyword_tree *tmp;
	tmp = roott;

	for(int i = 0 ; i < word.length(); i++) {
		if( tmp->next[ word[i]-97 ] == NULL ) //if state(node) is not present; make one
			tmp->next[ word[i]-97 ] = create_state();
		tmp = tmp->next[ word[i]-97 ];
	}
	tmp->isleaf = true;	//for final state; isleaf is true
}

//To calculate the total no of elements in string array keyword
int count_no_of_keyword()
{
	int count = 0;
	for(int i = 0; i < sizeof(keyword)/sizeof(*keyword); i++)
		if( keyword[i] != "")
			count++;
	return count;
}

//Loop through all keywords
void create_keyword_tree( struct keyword_tree *roott)
{
	for(int i = 0 ; i < count_no_of_keyword(); i++)
		make_node(keyword[i], roott);
}

bool is_keyword( string word, struct keyword_tree *roott )
{
	struct keyword_tree *tmp;
	tmp = roott;
	for(int i = 0 ; i < word.length(); i++){
		if( word[i] - 97 < 0 || word[i]-97 >= 26 ) return false; //if character is not lowercase letter
		if( tmp->next[ word[i] -97 ] == NULL )	//if state is not present; Consider only lowercase letters
			return false;
		tmp = tmp->next[ word[i]-97 ];
	}
	if( tmp != NULL && tmp->isleaf == true) // if temp is a final state
		return true;
	else
		return false;
}

int main()
{
	struct keyword_tree *roott;
	roott = create_state();
	create_keyword_tree(roott);

	string word;
	while(1) {
		cout<<"Please enter a word ( quit to exit) > ";
		cin>>word;
		if( word == "quit")
			break;

		if( is_keyword(word, roott))
			cout<<word<<" is a keyword\n";
		else
			cout<<word<<" is not a keyword\n";
	}
}
