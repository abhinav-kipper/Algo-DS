//Given an array A of N elements. Find the majority element in the array. 
//A majority element in an array A of size N is an element that appears more than N/2 times in the array
#include <bits/stdc++.h>
using namespace std;
int mooveVotingAlgo(vector<int>&v, int n){
    int potentialCandidateIndx = 0, count =1;
    for (int i=1;i<n;i++){
        if (v[potentialCandidateIndx] == v[i])
                count++;
        else count--;
        if (!count){
            potentialCandidateIndx = i;
            count =1;
        }
    }
    return v[potentialCandidateIndx];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for (int i=0;i<n;i++)
	    {
	        cin>>v[i];
	    }
	    int potentialCandidate = mooveVotingAlgo(v, n);
	    int count = 0,i;
	    for (i =0;i<n;i++){
	        if (v[i]==potentialCandidate){
	            count++;
	        }
	        if (count>n/2)
	        {
	            cout<<potentialCandidate<<endl;
	            break;
	        }
	    }
	    if (i==n)
	        cout<<(-1)<<endl;
	}
	return 0;
}
