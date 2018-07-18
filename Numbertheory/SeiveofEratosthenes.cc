#include<iostream>
using namespace std;

int makeSieve(int n){

	bool isPrime[n+1];
	for(int i=0;i<=n;i++){
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;

	for(int i=2;i*i<=n;i++){ //rest automatically done for more than root n
		if(isPrime[i] == true){
			for(int j=i*i;j<=n;j+=i){ //if prime make all of its multiples false as they are not prime
				isPrime[j] = false;
			}
		}
	}

	int count = 0;
	for(int i=0;i<=n;i++){
		if(isPrime[i] == true){ //count no of trues
			count++;
		}
	}
	return count;

}
int main(){
	int n;
	cin >> n;

	int nPrimes = makeSieve(n);
	cout<<nPrimes <<endl;
	return 0;
}
