#include<iostream>
using  namespace std;
//edge list

int *parent;

struct edges{
    int v1,v2,weight;
};

void initialize(int v)
{
    //making everyone their own parent
    parent=new int[v];
    for (int i=0;i<v;i++)
        parent[i]=i;
}

int find_parent(int i)
{
    while (parent[i]!=i)
    {
        i=parent[i];
    }
    return parent[i];
}
void union1 (int i,int j)
{
    int par_i=find_parent(i);
    int par_j=find_parent(j);
    parent[par_i]=par_j;
}


void kruskal(edges *a,int v,int e)
{
    int A=0,nextedge=0; //sorted edges came
    //No of edges in spanning tree would be v-1--------0 to v-1
    cout<<endl<<"*******SPANNING TREE WILL CONTAIN FOLLOWING EDGES************"<<endl<<endl;
   cout<<" vertex1 vertex2 weight "<<endl;

   while (A<v-1)
   {
       int curU=a[nextedge].v1;
       int curV=a[nextedge].v2;
       int weight=a[nextedge].weight;

       if (find_parent(curU)!=find_parent(curV))
       {
           A++; //added to spannning tree
           cout<<curU<<" "<<curV<<" "<<weight<<endl;
           union1(curU,curV);
       }
       nextedge++;
   }
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
    //bubble sorting edges in ascending order

    for (int i=0;i<e;i++)
    {
        for  (int j=0;j<e;j++)
        {
            if (a[j+1].weight<a[j].weight)
            {
                edges temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    cout<<endl<<"*******After sorting we have edges**********"<<endl<<endl;

        for(int i=0;i<e;i++)
        cout<<"  "<<a[i].v1<<"     "<<a[i].v2<<"     "<<a[i].weight<<endl;

        initialize(v);
        kruskal(a,v,e);
}
