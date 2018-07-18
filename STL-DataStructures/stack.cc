#include<bits/stdc++.h>
using namespace std;
vector <int> s;
main()
{
    s.push_back(1);
    s.push_back(6);
    s.push_back(5);
    s.push_back(2);
    s.push_back(3);
    vector <int> :: iterator i;
    for (i=s.begin();i!=s.end();i++)
        cout<<s[i];
}
