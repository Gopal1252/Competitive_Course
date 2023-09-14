//https://www.codechef.com/problems/DIVSUBS

//similar question: https://leetcode.com/problems/continuous-subarray-sum/
#include<bits/stdc++.h>
using namespace std;

//since every subarray is a subset and from the divisible subarrays question we saw that there will be at least one subarray such that (subarray sum)%m = 0, so we just need to find that subarray and it actually did work
//we just need to find one subarray and we know that it will exist
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    unordered_map<int,int> mp;
    mp[0] = -1;
    int prefix = 0;
    for(int i=0; i<n; i++){
        prefix = (prefix + 0LL + a[i]%n + n)%n;
        if(mp.find(prefix) != mp.end()){
            int st = mp[prefix];
            cout<<i - st<<endl;
            for(int j = st+1; j<=i; j++){
                cout<<j+1<<" ";
            }
            cout<<endl;
            return;
        }
        else{
            mp[prefix] = i;
        }
    }
    cout<<-1<<endl;
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