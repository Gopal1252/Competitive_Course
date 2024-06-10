#include<bits/stdc++.h>
using namespace std;

//Alice and Bob are playing a game where there are n coins. They must pick at least a and at max b coins.
//Alice goes first and the last one to pick wins. Who will win?
//Also if there are less than a coins left, player can take them all

//not sure if the code is correct or not
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,a,b;
    cin>>n>>a>>b;

    if(n%(a+b) == 0) cout<<"Bob";
    else cout<<"Alice";

    //Or may be this, but I think above two lines are enough
    // if(n>=a && n<=b){
    //     cout<<"Alice\n";
    // }
    // else{
    //     if(n%(a+b) == 0) cout<<"Bob";
    //     else cout<<"Alice";
    // }

    return 0;
}