#include<bits/stdc++.h>
using namespace std;

int a[10000];
int BIT[10000] = {0};

//TC:O(logN)
void update(int i, int inc, int N){
    while(i<=N){
        BIT[i] += inc;
        i += (i&(-i));
    }
}

//sum till index i
//TC:O(logN)
int query(int i){
    int ans = 0;
    while(i>0){
        ans += BIT[i];
        i-=(i&(-i));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    //Build the BIT
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i],n);
    }

    //query
    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(r) - query(l-1)<<"\n";
    }

    return 0;
}