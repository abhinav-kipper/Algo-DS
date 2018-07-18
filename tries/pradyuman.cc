#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
  public :
  TrieNode ** children;
  bool isend;
  TrieNode ()
  {
    children=new TrieNode * [26];
    for (int i=0;i<26;i++)
    		children[i]=NULL;
    isend=0;
	}
	
};
void insert(TrieNode * root,string s)
{
  TrieNode * current=root;
  for (int i=0;i<s.size();i++)
  {
    int index=s[i]-'a';
    TrieNode * child=current->children[index];
    if (!child)
    {
    	//cout<<index<<" ";
      child = new TrieNode ();
      current->children[index]=child;
    }
    current=child;
  }
  current->isend=1;
  
  
}
void dfs(TrieNode* root, string prefix)
{
	if(root->isend)
	cout<<prefix<<endl;
	

	
	for (int i=0;i<26;i++)
	{
		
		if(root->children[i])
		dfs(root->children[i],prefix+char(i+'a')) ;
	}
}
bool suggestions (TrieNode * root,string prefix)
{
	TrieNode * current=root;
	
	for(int i=0;i<prefix.length();i++)
	{
		int index=prefix[i]-'a';
		TrieNode * child =current->children[index];
		if (!child) return 0;
		 
		current=child;
	}

	dfs(current,prefix);
	return 1;
}
int main()
{
	int n,q;
	cin>>n;
	TrieNode * root=new TrieNode();
	while (n--)
	{
		string  s;
		cin>>s;
		insert(root,s);
	}
	cin>>q;
	while (q--)
	{
		string pre;
		cin>>pre;
		bool x= suggestions(root,pre);
		if (x==0) cout<<"No suggestions"<<endl;
	}
	
    return 0;
}

