#include<bits/stdc++.h>
using namespace std;
struct item{
int value,weight;
};
bool compare(struct item a,struct item b)
{
    double value1=((double)a.value)/(a.weight);
    double value2=((double)b.value)/(b.weight);
    return value1>value2;
    //whoever greater
}
double fKnapsack(struct item arr[],int W,int  n)
{
    sort(arr,arr+n,compare);
    int  currw=0;
    double fvalue=0;
    for (int  i=0;i<n;i++)
    {
        if (currw+arr[i].weight<=W)
        {
            currw+=arr[i].weight;
            fvalue+=arr[i].value;
        }
        else {
        int  rweight=W-currw;
        fvalue+=arr[i].value*((double)rweight/arr[i].weight);
        break;

        }
    }
    return fvalue;
}
int main()
{
    int  w=70;
    item a[]={{60,20},{70,15},{80,40}};
    cout<<"Maximum value is "<<fKnapsack(a,w,3);
    return 0;
}
