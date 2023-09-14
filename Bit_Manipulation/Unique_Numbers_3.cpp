//https://hack.codingblocks.com/app/practice/5/433/problem
#include<bits/stdc++.h>
using namespace std;

/*
We are given an array containg n numbers. 
All the numbers are present thrice except for one number which is only present once. 
Find the unique number. Only use - bitwise operators, and no extra space.
*/

//Let's assume that the one no. which occurs only once is not there
//now if we count no. of set bits at each index, answer shoul be a multiple of 3
//so let's count no if set bits at each location and then take %3, this will leave us with 1 at positions where the target no.'s bits are set
int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sol[32];

    for(int i=0;i<32;i++){
        int ans = 0;
        for(int j=0;j<n;j++){
            ans +=((arr[j]>>i)&1);
        }
        sol[i] = ans;
    }

    for(int i=0;i<32;i++){
        sol[i] = sol[i]%3;
    }

    int decimal = 0;
    for(int i=0;i<32;i++){
        decimal += (pow(2,i)*sol[i]);
    }
    cout<<decimal<<endl;
    return 0;
}