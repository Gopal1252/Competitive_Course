//https://www.spoj.com/problems/INVCNT/
//https://leetcode.com/problems/reverse-pairs/description/ {much more difficult than the normal inversion count using BIT, not done yet, see the editorial}
#include<bits/stdc++.h>
using namespace std;

int a[10000];
int BIT[10000] = {0};

void update(int i, int inc, int N){
    while(i<=N){
        BIT[i] += inc;
        i += (i&(-i));
    }
}

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

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    //Inversion Count
    int ans = 0;
    for(int i=n;i>=1;i--){
        ans += query(a[i]-1);
        update(a[i],1,n);
    }


    return 0;
}