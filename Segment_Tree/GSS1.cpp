//https://www.spoj.com/problems/GSS1/
#include<bits/stdc++.h>
using namespace std;
#define INT_MIN -22121
const int N = 50010;

class treeNode{
    public:
    int prefix;
    int suffix;
    int total;
    int max_sum;
};

int arr[N];
treeNode tree[4*N+1];

void buildTree(int s, int e, int index){//s,e -> start and end indexes of array a, index -> index of node in the segment tree
     //base case
    if(s==e){
        tree[index] = ((treeNode){arr[s],arr[s],arr[s],arr[s]});
        return;
    }

    //recursive case
    int mid = (s+e)/2;
    buildTree(s,mid,2*index);
    buildTree(mid+1,e,2*index+1);

    treeNode left = tree[2*index];
    treeNode right = tree[2*index+1];


    tree[index].prefix = max(left.total+right.prefix,left.prefix);
    tree[index].suffix = max(right.total+left.suffix,right.suffix);
    tree[index].total = left.total+right.total;
    tree[index].max_sum = max(max(left.max_sum,right.max_sum),left.suffix+right.prefix);

    return;
}

treeNode query( int ss, int se, int qs, int qe, int index){//ss,se -> start and end of segment tree node's range---------qs,qe -> start and end of query's range 
    //Complete Overlap
    if(qs<=ss && se<=qe){
        return tree[index];
    }
    //No Overlap
    else if(qe<ss || qs>se){
        return ((treeNode){INT_MIN,INT_MIN,INT_MIN,INT_MIN});
    }
    //Partial Overlap
    int mid = (ss + se)/2;
    treeNode left = query(ss,mid,qs,qe,2*index);
    treeNode right = query(mid+1,se,qs,qe,2*index+1);

    treeNode temp;

    temp.prefix = max(left.total+right.prefix,left.prefix);
    temp.suffix = max(right.total+left.suffix,right.suffix);
    temp.total = left.total+right.total;
    temp.max_sum = max(max(left.max_sum,right.max_sum),left.suffix+right.prefix);

    return temp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildTree(0,n-1,1);

    int m;
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        treeNode ans = query(0,n-1,l,r,1);
        cout<<ans.max_sum<<'\n';
    }
    return 0;
}