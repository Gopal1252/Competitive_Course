#include<bits/stdc++.h>
using namespace std;

vector<int> BIT(1000), a(1000);
int n;

void update(int x, int delta){
    for(;x<=n;x+=x&-x){
        BIT[x] += delta;
    }
}

int query(int x){
    int sum = 0;
    for(;x>0;x-=x&-x){
        sum += BIT[x];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i]);
    }

    return 0;
}