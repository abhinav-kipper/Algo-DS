#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int,int> > > graph,int source ,int  distance[])
{
    set < pair <int ,int > > set_min;
    int n=graph.size(); // 1 addressing
    bool visited [n];
    memset(visited , 0 , sizeof(visited));
    
    distance[source]=0;
    set_min.insert( {distance[source],source} );
    while (!set_min.empty())
    {
        pair<int,int> curr= (*set_min.begin());
        set_min.erase(set_min.begin());
        int curr_vertex=curr.second;
        int curr_vertex_dist=curr.first;
        if (visited[curr_vertex]) continue;
        visited[curr_vertex]=true;
        for (int i=0;i<graph[curr_vertex].size();i++)
        {
            int node=graph[curr_vertex][i].first;
            int weight_from_cur=graph[curr_vertex][i].second;
            if ( distance[node]> distance[curr_vertex]+weight_from_cur)
            		{
            				set_min.erase({distance[node],node});
            			distance[node]=distance[curr_vertex]+weight_from_cur;
            		
            			set_min.insert({distance[node],node});
					}
        }
    }
    	for ( int i=0;i<n;i++)
	 			cout<<distance[i]<<" ";
	 			cout<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while  (t--)
	{
	    int n,e;
	    cin>>n>>e;
	    vector< vector<pair<int,int> > > graph;
	    graph.resize(n);
	    int x,y,w;
	  	for ( int i=0;i<e;i++)
	  	{
	  		cin>>x>>y>>w;
	  		graph[x].push_back({y,w}); //directed graph
		}
	   int  source=1;
	   //int dest; cin>>dest;
	     int distance[n];
	     //memset(distance , INT_MAX , sizeof(distance));
	     for (int i=0;i<n;i++) distance[i]=INT_MAX;
	    dijkstra(graph,source,distance);
	 	for ( int i=0;i<n;i++)
	 			cout<<distance[i]<<" ";
	}
	return 0;
}
