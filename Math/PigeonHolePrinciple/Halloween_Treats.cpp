// https://www.spoj.com/problems/HALLOW/
//same as Divisible_Subsets/Subarrays
//if you get a little confused as to how pigeonhoe principle is being applied here, see this codeforces link: https://codeforces.com/blog/entry/60485
/*(I)
since every subarray is a subset and also it's given that n>=c, 
so there will always be at least one subarray where (subarray sum)%c = 0,
 so we just need to find the first such subarray
*/
#include<bits/stdc++.h>
using namespace std;

void solve(int c, int n){
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    unordered_map<int,int> mp;
    mp[0] = -1;
    int prefix = 0;
    for(int i=0; i<n; i++){
        prefix = (prefix + 0LL + a[i]%c + c)%c;
        if(mp.find(prefix) != mp.end()){
            int st = mp[prefix];
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
    cout<<"no sweets"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(true){
        int c,n;
        cin>>c>>n;
        if(c == 0 && n == 0) break;
        solve(c,n);
    }

    return 0;
}