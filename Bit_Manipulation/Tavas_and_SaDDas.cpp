//https://codeforces.com/problemset/problem/535/B
//https://hack.codingblocks.com/app/practice/5/660/problem
//this s my own solution
#include<bits/stdc++.h>
using namespace std;

int digCnt(int n){
    int ans = 0;
    while(n){
        ans++;
        n/=10;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int cnt = digCnt(n);
    
    int ans = 0;
    for(int i=1;i<cnt;i++){
        ans += pow(2,i);
    }
    int pos = 0;
    int temp = n;
    int i = 0;
    while(temp){
        int x = temp%10;
        temp/=10;
        if(x == 4){
            pos += pow(2,i)*0;
        }
        else{
            pos += pow(2,i)*1;
        }
        i++;
    }
    ans+=pos+1;
    cout<<ans;


    return 0;
}