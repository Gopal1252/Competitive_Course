//https://hack.codingblocks.com/app/practice/5/404/problem
#include<bits/stdc++.h>
using namespace std;

/*
We are given an array containg n numbers. 
All the numbers are present twice except for one number which is only present once. 
Find the unique number without taking any extra spaces and in linear time. ( Hint - Use Bitwise )
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans^=a[i];
	}
	cout<<ans;

    return 0;
}