//Given a number N, find it's binary representation
#include<bits/stdc++.h>
using namespace std;

void decimalToBinary(int n){
    int ans = 0;
    int power = 1;
    while(n>0){
        int last_bit = (n&1);
        ans += (last_bit*power);
        n = (n>>1);
        power*=10;
    }
    cout<<ans;
}

int main(){

    int n;
    cin>>n;
    decimalToBinary(n);

    return 0;
}