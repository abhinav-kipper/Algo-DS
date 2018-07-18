#include<iostream>
using namespace std;

bool checkPrime(int n){

	int count = 0;
	for(int i=1;i*i<=n;i++){

		if(n%i == 0){
			if(i*i == n){
				count+=1;
			}else{
				count+=2;
			}
		}
	}

	if(count == 2){
		return true;
	}
	return false;
}
int main(){

	int n;
	cin >> n;
	int count = 0;
	for(int i=1;i<=n;i++){
		if(checkPrime(i) == true){
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
