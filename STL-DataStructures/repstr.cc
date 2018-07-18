/**/
#include<iostream>
#include<cstring>
#include<set>
#include<map>
using namespace std;


char nonRepeatingCharacter(string str){

  //Write your code here
  map<char,int> m;
  map<char,int>::iterator it;
  for (int i=0;i<str.length();i++)
    m[str[i]]++;
  char res=str[0];
    for (int i=1;i<str.length();i++){
        if(m[str[i]]==1)
        {
            res=str[i];
            break;
        }
    }

  return res;



}
