#include<iostream>
#include<vector>
#include<set>
using namespace std;


vector<int> removeDuplicates(vector<int> input){

    // Write your code here

  set<int> s;

  vector <int> result;
for (int i=0;i<input.size();i++)
{

  if(s.find(input[i])==s.end())
  {
    result.push_back(input[i]);
    s.insert(input[i]);
  }
}

  return result;

}


