#include<iostream>
#include<vector>
using namespace std;
main()
{
    vector <int> v(5);
    for (int i=0;i<v.size();i++)
        cin>>v[i];
    vector<int>::iterator it;
    v.push_back(100);
    for (it=v.begin();it!=v.end();it++)
            cout<<*it<<" ";


}
