/* Given a dictionary, a method to do lookup in dictionary and
a M x N board where every cell has one character. 
Find all possible words that can be formed by a sequence of adjacent characters. 
Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.*/
#include <bits/stdc++.h>
using namespace std;
bool visited[1000][1000] ={{false}};

void findWords(vector<vector<char>> &a, int i, int j, string &str
,unordered_set<string> dict, int m, int n, set<string> &result){
    visited[i][j]=true;
    str+=a[i][j];
    if (dict.find(str)!=dict.end()){
        result.insert(str);
    }
    for (int row = i-1; row<=i+1;row++){
        for (int col=i-1;col<=i+1;col++){
            if (row>=0 && col>=0 && row<n && col<m && !visited[row][col]){
                findWords(a,row,col,str,dict, m, n, result);
            }
        }
    }
    str.erase(str.length()-1);
    visited[i][j]=false;
}
int main() {
	//code
	int t;
	cin>>t;
	while (t--){
	    int x;
	    cin>>x;
	    unordered_set<string> dict;
	    set<string> result;
	    while(x--){
	        string k;
	        cin>>k;
	        dict.insert(k);
	    }
	    int n,m;
	    cin>>n>>m;
	    vector<vector<char>> a(n, vector<char>(m,0));
	    for (int i=0;i<n;i++){
	        for (int j=0;j<m;j++){
	            cin>>a[i][j];
	        }
	    }
	    string matching_string = "";
	    for (int i=0;i<n;i++)
	    {
	        for (int j=0;j<m;j++){
	            findWords(a, i, j, matching_string, dict, m, n, result);
	        }
	    }
	    for (int i=0;i<n;i++){
	        for (int j=0;j<m;j++){
	            visited[i][j]= false;
	        }
	    }
	    set<string>:: iterator it;
	    for (it=result.begin(); it!=result.end();it++){
	        cout<<(*it)<<" ";
	    }
	    cout<<endl;
	    
	}
	
	return 0;
}
