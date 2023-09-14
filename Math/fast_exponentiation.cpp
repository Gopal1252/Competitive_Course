#include<bits/stdc++.h>
using namespace std;

//fast exponentiation
//It is faster way to compute a^n

//If n is odd -> a^n = a*(a^(n/2))^2
//If n is even -> a^n = (a^(n/2))^2

//TC:O(log(n)) {n is the power}
int pow(int a, int n){
    if(n == 0) return 1;

    int subprob = pow(a,n/2);

    //check if odd or even
    if(n&1){
        return a * subprob*subprob;
    }
    return subprob * subprob;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a,n;
    cin>>a>>n;
    cout<<pow(a,n);
    return 0;
}