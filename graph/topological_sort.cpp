void dfs_topo(vector<int > graph[],int source,bool visited[],stack<int> &order_stack)
{
    visited[source]=true;
    for (int i=0;i<graph[source].size();i++)
    {
        if (visited[graph[source][i]]==false)
            dfs_topo(graph,graph[source][i],visited,order_stack);
    }
    order_stack.push(source);
}
int * topoSort(vector<int> graph[], int N)
{
        //pre_work
        bool visited[N];
        //memset(visited,0,sizeof(visited));
        for (int i=0;i<N;i++)
                visited[i]=false;
        stack<int> order_stack;
        for (int i=0;i<N;i++)
        {
            if (visited[i]==false){
               dfs_topo(graph,i,visited,order_stack);
            }
                    
        }
        int * res=new int[order_stack.size()];
        int i=0;
        while (!order_stack.empty())
            {
                res[i++]=order_stack.top();
                order_stack.pop();
            }
            return res;
}
