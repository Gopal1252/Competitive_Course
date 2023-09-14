//https://hack.codingblocks.com/app/practice/5/213/problem

/*
We are given an array containg n numbers. 
All the numbers are present twice except for two numbers which are present only once. 
Find the unique numbers in linear time without using any extra space.
*/

/*
step1: find xor of all the numbers which is ultimately the xor of the two unique numbers(let first,second), then ans = first^second
step2: then we find the msb of ans. Note that msb of ans will be becoz of the presence of 1 at msb position in either first or second, not both
step3: we will find xor of all the numbers in the given array with 1 at msb position. The answer will be either first or second.
step 4: for second, take xor of first with ans
*/

#include<bits/stdc++.h>
using namespace std;

int find_msb(int n){
	int msb = 0;
	n = (n>>1);
	while(n != 0){
		n = (n>>1);
		msb++;
	}
	return msb;
}

int main() {
	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		ans ^=a[i];
	}

	int msb = find_msb(ans);

	int first = 0;

	for(int i=0;i<n;i++){
		if(((a[i]>>msb)&1) == 1){
			first ^= a[i];
		}
	}

	int second = (first^ans);

	cout<<min(first,second)<<" "<<max(first,second);

	return 0;
}