#include <bits/stdc++.h>
using namespace std;
//bfs

int  bfs ( vector<vector<int > > & graph, int source )
{
     bool visited[30];
     memset ( visited , 0 , sizeof ( visited ));
     queue<pair<int  ,int > > q;
     pair<int ,int > p=make_pair( source , 0);
     q.push(p);
     
     while (!q.empty())
     {
          pair<int ,int > cur=q.front();
          q.pop();
          visited[cur.first]=true;
          if (cur.first==30)
                return cur.second;
                
          for ( int i=0;i<graph[cur.first].size();i++)
          {
          		if (visited[graph[cur.first][i]]) continue;
              pair<int ,int > p = make_pair(graph[cur.first][i],cur.second+1);
              q.push(p);
              
          }
     }
}
int main() {
	//code
	int t;
	cin>>t;
	while (t--)
	{
	    int n;
	    cin>>n;
	    vector<vector<int > > v(31);
	    int a,b;
		map <int ,int > lad_snake;
	    for (int i=0;i< n ;i++)
	    {
	        cin>>a>>b;
	        
	        lad_snake[a]=b;
	       
	    
		}
		
	    for ( int i=0;i<v.size();i++)
	    {
	    	
	        int j=i+1;
	        while (j<v.size() && j<=i+6)
	        {
	        	if (lad_snake.find(j)==lad_snake.end())
	            v[i].push_back(j);
	            else  v[i].push_back(lad_snake[j]);
	            j++;
	            
	        }
	    }
	    
	    cout<<bfs(v,1)<<endl;
	
	}
	return 0;
}
