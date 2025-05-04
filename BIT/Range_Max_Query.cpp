//Range Max Query (Using BIT/Fenwick Tree) {with updates, ofcourse} {point updates}
//Using BIT, we can easily find the max element in range (1,i)
//Sir didn't do for range (i,j)

#include<bits/stdc++.h>
using namespace std;

int a[10000];
int BIT[10000] = {0};

void update(int i, int val, int N){
    while(i<=N){
        BIT[i] = max(BIT[i],val);
        i += (i&(-i));
    }
}

//max element till index i
int query(int i){
    int ans = 0;
    while(i>0){
        ans += max(ans,BIT[i]);
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
        int ind;
        cin>>ind;
        cout<<query(ind)<<"\n";
    }

    return 0;
}