#include<iostream>
using namespace std;
//edge list
int dist[10000];
struct edges{
    int v1,v2,weight;
};
void relax(int u,int  v,int  weight)
{
    if (dist[v]>dist[u]+weight)
        dist[v]=dist[u]+weight;
}
bool bellmanford(edges *a,int v,int e,int source)
{
    //INITIALIZE SINGLE SOURCE

    for (int i=0;i<v;i++)
        dist[i]=INT_MAX;
    dist[0]=0;

    for (int i=0;i<v;i++)
    {
        for (int j=0;j<e;j++)
        {
            relax(a[j].v1,a[j].v2,a[j].weight);
        }
    }

    //Negative weight cycle
    for (int j=0;j<e;j++)
    {
        if (dist[a[j].v2]>dist[a[j].v1]+a[j].weight)
            return false;
    }
    return true;


}
int  main()
{
    int v,e;
    cout<<"Enter no of vertices:";
    cin>>v;
    cout<<"Enter no of edges:";
    cin>>e;

    edges * a=new edges[e];

    for (int i=0;i<e;i++)
    {
        cout<<"Enter the edge "<<i+1<<" as (v1 v2 weight):"<<endl;
        cin>>a[i].v1>>a[i].v2>>a[i].weight;
    }

    //input done-----
        if (bellmanford(a,v,e,0))
        {
                cout<<"**** Distance of each vertex from source vertex 0 is ***** "<<endl ;
                for (int i=0;i<v;i++)
                {
                cout<<"Distance of "<<i<<" is: "<<dist[i]<<endl;
                }
        }
        else cout<<"Negative cycle exists";
}
