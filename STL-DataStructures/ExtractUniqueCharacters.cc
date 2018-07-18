#include<bits/stdc++.h>
#include<map>
using namespace std;
char* uniqueChar(char *str){
    // Write your code here
	map<char,int> m;
  for (int  i=0;str[i]!='\0';i++)
  {
    m[str[i]]++;
  }
  int k=0;
  char *s=new char(strlen(str));
  for (int i=0;str[i]='\0';i++)
  {
    if (m[str[i]]=1)
      s[k++]=str[i];
  }
  s[k]='\0';
  return s;



}


main()
{
    char *str="aabhsadf";
    char *a;
    a=uniqueChar(str);
    for (int i=0;a[i]!='\0';i++) cout<<a[i];
}
