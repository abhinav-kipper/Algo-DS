#include<iostream>
using namespace std;
int count(int n){
    if(n == 0){
        return 0;
    }
    int smallAns = count(n / 10);
    return smallAns + 1;
}
main()
{
    int a=count(49123);
    cout<<a;
}
