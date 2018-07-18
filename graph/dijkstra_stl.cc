#include <bits/stdc++.h>
#define pp pair<int ,int >
using namespace std;
class Prioritize
{
  public:
  			int operator () (pp &p1 ,pp &p2)
            {
              return p1.second<p2.second;
			}
};

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
  vector<vector<pp> > > Graph(V);
  priority_queue<pp,vector<pp>,Prioritize> Q;
  int v1,v2,w;
  for (int i=0;i<E;i++)
  {
    cin>>v1>>v2>>w;
    Graph[v1].push_back(pp(v2,w));
    Graph[v2].push_back(pp(v1,w));
}
  vector<int > dist(n);
  for (int i=0;i<n;i++)
    		dist[i]=INT_MAX;
  int source=0;
  dist[source]=0;
  
  Q.push(pp(source,dist[source]));
  while (!Q.empty())
  {
    int minima=Q.top().first;
    Q.pop();
    int  all_neighbours=Graph[minima].size();
    for (int i=0;i<all_neighboburs;i++)
    {
      int cur=Graph[minima][i].first;
      int  dist_btw_cur_minima=Graph[minima][i].second;
      if (dist[cur]>  dist[minima] + dist_btw_cur_minima )
      {
        		dist[cur]=dist[minima] + dist_btw_cur_minima;
        		Q.push(pp(cur,dist[cur]));
	  }
    }
  }
  
  for (int i=0;i<n;i++)
  {
    cout<<i<<" "<<dist[i]<<endl;
	}



  return 0;
}

