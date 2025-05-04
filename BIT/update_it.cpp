//https://www.spoj.com/problems/UPDATEIT/
#include<bits/stdc++.h>
using namespace std;

void update(int ind, int inc, vector<int>& bit){
    while(ind<bit.size()){
        bit[ind]+=inc;
        ind += (ind&(-ind));
    }
}

int query(int ind,vector<int>& bit){
    int ans = 0;
    while(ind>0){
        ans += bit[ind];
        ind -= (ind&(-ind));
    }
    return ans;
}

void solve(){
    int n,u;
    cin>>n>>u;

    vector<int> bit(n+2);
    while(u--){
        int l,r,val;
        cin>>l>>r>>val;
        update(l+1,val,bit);
        update(r+2,-val,bit);
    }
    int q;
    cin>>q;

    while(q--){
        int x;
        cin>>x;
        cout<<query(x+1,bit)<<"\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}