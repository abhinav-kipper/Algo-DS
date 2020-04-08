#include <bits/stdc++.h>
using namespace std;
void print(vector<char> subsequence){
    for (auto s: subsequence){
        cout<<s<<" ";
    }
    cout<<endl;
}
void printSubsequences(string s, int i,int n, vector<char> & subsequence){
    if (i==n){ print(subsequence); return;}
    printSubsequences(s,i+1,n,subsequence);
    subsequence.push_back(s[i]);
    printSubsequences(s,i+1,n,subsequence);
    subsequence.pop_back();
}
int main() {
	// your code goes here
	vector<char> subsequence;
	printSubsequences("abcd",0,4, subsequence);
	return 0;
}
