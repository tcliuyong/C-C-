#include <cstring>
using namespace std;
struct node
{
	bool isWord;
	node *next[26];
	node()
	{
		isWord = false;
		for(int i=0;i<26;i++)
			next[i] = NULL;
	}
};
class Trie
{
public:
	node *root;
	Trie(){root = NULL;}
	void insert(string str)
	{
		if(!root)
			root = new node;
		node *location = root;
		for(int i=0;i<str.length();i++)
		{
			int num = str[i] - 'a';
			if(location->next[num] == NULL)
			{
				location->next[num] = new node;
			}
			location = location->next[num];
		}
		location->isWord = true;
	}
	bool search(string str)
	{
		node *location = root;
		for(int i=0;i<str.length();i++)
		{
			int num = str[i] - 'a';
			if(location->next[num] == NULL)
				return false;
			location = location->next[num];
		}
		return location->isWord;
	}
};