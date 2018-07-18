#include <bits/stdc++.h>
using namespace std;

main()
{
    priority_queue<int> g;
    g.push(10);
    g.push(13);
    g.push(0);
    g.push(2);
    g.push(4);
    g.push(9);
    while(!g.empty())
    {
        cout<< g.top();
        g.pop();
    }

    cout<<"Size:\n";
    cout<<g.size();
    cout<<g.top();

}
