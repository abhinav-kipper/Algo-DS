#include <iostream>
using namespace std;

int main() {
	int i = 10;
	int j = 21;
	int const * p = &i; //p is a pointer to constant integer

	p = &j;

	int * const p2 = &i; //2 is a constant pointer to an inteder
	(*p2)++;
	//p2 = &j; cant do as  now p2 is constant


	int const * const p3 = &i;
	p3 = &j;
	(*p3)++;
}

