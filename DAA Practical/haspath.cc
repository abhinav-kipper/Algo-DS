#include <iostream>
///WRONG CODE\\\\\\\\\\\\\\\\\
using namespace std;
bool haspathdfs(int ** edges,int V,int startVertex,int v2,bool * visited)
{
  bool flag=false;
  visited[startVertex]=true;
  if (v2==startVertex)
  		flag=true;
  for (int i=0;i<V;i++)
  {
    if (visited[i]==false && edges[startVertex][i]==1)
    {
        haspathdfs(edges,V,i,v2,visited);
    }
  }
  return flag;

}
int main() {
    int V, E;
    cin >> V >> E;
  int ** edges=new int *[V];
  for  (int i=0;i<V;i++)
  {
    edges[i]= new int[V];
    for(int j=0;j<V;j++)
      edges[i][j]=0;
  }
  for (int i=0;i<E;i++)
  {
    int  f,s;
    cin>>f>>s;
    edges[f][s]=1;
    edges[s][f]=1;
  }
  int  v1,v2;
  cin>>v1>>v2;
  bool*visited=new bool [V];
  for(int i=0;i<V;i++)
  {
    visited[i]=false;
  }
  bool a=haspathdfs(edges,V,v1,v2,visited);
  if (a==0)
		cout<<"false";
  else cout<<"true";
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself

  */

  return 0;
}
