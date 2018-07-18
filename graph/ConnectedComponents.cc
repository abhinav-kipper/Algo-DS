#include<iostream>
#include<vector>
//#include<set>
#include<bits/stdc++.h>
using namespace std;
//adjACENCY LIST using array of vectors
//indexing changed 1 to 0 and reverse pack
void dfs(vector<int> * edges,int start,set<int> * component,bool * visited)
{
    visited[start]=true;
    component->insert(start);
    for  (int i=0;i<edges[start].size();i++){
        int next=edges[start][i];
        if (!visited[next]){
            dfs(edges,next,component,visited);
        }
    }
}
set<set<int> *> * getComponents(vector<int> * edges,int n)
{
    //use map for better performance
    bool * visited = new bool[n];
    for (int i=0;i<n;i++)
        visited[i]=false;
    set<set<int> *>* output=new set<set<int>*>();

    for (int  i=0;i<n;i++)
    {
        if (!visited[i])
        {
            set<int>* component=new set<int>();
            dfs(edges,i,component,visited);
            output->insert(component);
        }
    }
    delete [] visited;
    return output;

}
int main()
{
    int n;
    cin>>n;
    vector<int> * edges=new vector<int> [n];

    for (int i=0;i<n;i++)
    {
        int j,k;
        cin>>j>>k;
        edges[j-1].push_back(k-1);
        edges[k-1].push_back(j-1); // undirected graph
    }
    //returning set of sets
    set <set<int> *> * components=getComponents(edges,n);
    set<set<int>*>:: iterator it1=components->begin();
    while(it1!=components->end())
    {
        set<int>* component =*it1;
        set<int>::iterator it2=component->begin();
        while(it2!=component->end())
        {
            cout<<*it2+1<<" "; //for 1 indexing
            it2++;
        }
        cout<<endl;
        delete component;
        it1++;
    }
    delete components;
    delete [] edges;
}

