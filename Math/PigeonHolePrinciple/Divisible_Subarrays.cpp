// https://hack.codingblocks.com/app/contests/31/1065/problem

//Same/Similar Questions on Leetcode: {don't actually use pigeonhole priinciple since value of k is not necessarily N in these {see question to understand what is k}}
//https://leetcode.com/problems/subarray-sums-divisible-by-k/
//https://leetcode.com/problems/continuous-subarray-sum/
#include<bits/stdc++.h>
using namespace std;

/*
You are given N elements, a1,a2,a3….aN. 
Find the number of good sub-arrays.
A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.
*/

#define ll long 

int a[1000005], pre[1000005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        memset(pre,0,sizeof(pre));
        pre[0] = 1;
        //read the input
        int sum = 0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            sum += a[i];
            sum %= n;
            sum = (sum + n)%n;
            pre[sum]++;
        }

        ll ans = 0;
        for(int i=0; i<n; i++){
            ll m = pre[i];
            ans += (m)*(m-1)/2;
        }
        cout<<ans<<endl;
    }

    return 0;
}