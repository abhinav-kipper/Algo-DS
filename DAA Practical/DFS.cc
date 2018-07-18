#include<iostream>
using namespace std;
//Adjacency matrix

void dfs(int ** edges,int n,int startVertex,bool *visited)
{
   //if(visited[startVertex]==true)
   //{

     //  cout<<"Cycle deteted " <<endl;
   //}
    cout<<startVertex<<endl;

    visited[startVertex]=true;
    for  (int i=0;i<n;i++)
    {
        if (i==startVertex){
            continue;
        }
        if (edges[startVertex][i]==1){
                if (!visited[i]){
                    dfs(edges,n,i,visited);
                }
        }
    }
}


int  main()
{
    int vertices,edge;
    cin>>vertices>>edge;
    int **edges=new int *[vertices];
    for (int i=0;i<vertices;i++)
    {
        edges[i]=new int [vertices];
        for  (int j=0;j<vertices;j++)
            edges[i][j]=0;
    }

    for  (int i=0;i<edge;i++)
    {
        int first,second;
        cin>>first>>second;
        edges[first][second]=1;
        edges[second][first]=1;
    }
    bool *visited=new bool[vertices];
    for (int i=0;i<vertices;i++)
        visited[i]=false;

     cout<<"DFS"<<endl;
     dfs(edges,vertices,0,visited);

     //delete matrices
     delete[] visited;
     for (int i=0;i<vertices;i++)
        delete [] edges[i];
     delete [] edges;

}
