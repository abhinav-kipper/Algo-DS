#include<iostream>
using namespace std;

int min_vertex(int **mat,bool *visited,int *dist,int  v)
{
    int mindist=INT_MAX,min;
    for (int i=0;i<v;i++)
    {
        if (visited[i]==0 && dist[i]<mindist)
        {
            mindist=dist[i];
            min=i;
        }
    }
    return min;
}

int main()
{
    int v,e;
    cout<<"Enter the no of vertices:";
    cin>>v;
    int **mat=new int*[v];
    for (int i=0;i<v;i++)
    {
        mat[i]=new int[v];
        for (int j=0;j<v;j++)
            mat[i][j]=0;
    }

    cout<<"Enter the no of edges:";
    cin>>e;


    for (int i=0;i<e;i++)
    {
        int first,second,weight;
        cin>>first>>second>>weight;
        mat[first][second]=weight;
        mat[second][first]=weight;
    }

    //Graph implementation ended-------------------------------------

    bool visited[v]={false};
    //int parent[v];
    //parent[0]=0;


    int dist[v];

    for (int i=0;i<v;i++)
        dist[i]=INT_MAX;
    dist[0]=0;

    for (int i=0;i<v;i++)
    {
        int min=min_vertex(mat,visited,dist,v);
        visited[min]=true;
        for (int j=0;j<v;j++)
        {
            if (mat[min][j]!=0 && visited[j]==false && dist[j]>=mat[min][j]+dist[min])
            {
                dist[j]=mat[min][j]+dist[min];
                //parent[j]=min;
            }
        }
    }

    cout<<"**** Distance of each vertex from source vertex 0 is ***** "<<endl ;
    for (int i=0;i<v;i++)
    {
        cout<<"Distance of "<<i<<" is: "<<dist[i]<<endl;
    }
    return 0;

}
