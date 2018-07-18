#include<iostream>
using namespace std;

void removeConsecutiveDuplicates(char *input) {

	if (input[1]=='\0')
      return ;

  if (input[0]==input[1])
  {
    int i=1;
    for (;input[i]!='\0';i++)
      	input[i-1]=input[i];
    input[i-1]=input[i];
	removeConsecutiveDuplicates(input);
  }
  	else removeConsecutiveDuplicates(input+1);


}
main()
{
    int t;
    cin>>t;
    while (t--){
    char str[100];
    cin>>str;
    removeConsecutiveDuplicates(str);
    cout<<str;
}
}
