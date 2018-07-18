#include<iostream>
using namespace std;

void removeX(char s[])
{
    //base case
    if (s[0]=='\0')
        return ;

        //ONLY TAKES CARE OF FIRST ELEMENT REST RECURSION WILL
    if (s[0]!='x')  //if not x NO NEED TO DO ANYTHING
        removeX(s+1); //CALL FOR REST ** REMOVE X FROM REST
    else
    {
        int i=1;
        for (;s[i]!='\0';i++)
            s[i-1]=s[i]; //shift all to right to remove x from s[0]
        s[i-1]=s[i];//Copy NUll char

        removeX(s);
    }
}
main()
{
    char str[100];
    cin>>str;
    removeX(str);
    cout<<str;
}
