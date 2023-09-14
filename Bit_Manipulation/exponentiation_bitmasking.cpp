#include<bits/stdc++.h>
using namespace std;

//exponentiation/power using Bitmasking(much faster than normal)
int power_optimised(int a, int n){
    int ans = 1;

    while(n>0){
        int last_bit = (n&1);
        if(last_bit == 1){
            ans = ans*a;
        }
        a = a*a;
        n = (n>>1);
    }
    return ans;
}

int main(){
    int a,n;
    cin>>a>>n;

    cout<<power_optimised(a,n);

    return 0;
}