#include<iostream>
#include<queue>
using namespace std;
//Adjacency matrix

void bfs(int **edges,int vertices,int startVertex,bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(startVertex);
    visited[startVertex]=true;
    while (!pendingVertices.empty())
    {
        int currentVertex=pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<endl;
        for (int i=0;i<vertices;i++) //adjacent
        {
            if (i==currentVertex)
                continue;
            if (edges[currentVertex][i]==1 && !visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
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

     cout<<"BFS"<<endl;
     bfs(edges,vertices,0,visited);

     //delete matrices
     delete[] visited;
     for (int i=0;i<vertices;i++)
        delete [] edges[i];
     delete [] edges;

}
