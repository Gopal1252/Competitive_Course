#include<bits/stdc++.h>
using namespace std;

void buildTree(int *a, int s, int e, int *tree, int index){//s,e -> start and end indexes of array a, index -> index of node in the segment tree
     //base case
    if(s==e){
        tree[index] = a[s];
        return;
    }

    //recursive case
    int mid = (s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);

    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

int query(int *tree, int ss, int se, int qs, int qe, int index){//ss,se -> start and end of segment tree node's range---------qs,qe -> start and end of query's range 
    //Complete Overlap
    if(qs<=ss && se<=qe){
        return tree[index];
    }
    //No Overlap
    else if(qe<ss || qs>se){
        return INT_MAX;
    }
    //Partial Overlap
    int mid = (ss + se)/2;
    int left = query(tree,ss,mid,qs,qe,2*index);
    int right = query(tree,mid+1,se,qs,qe,2*index+1);

    return min(left, right);
}

void updateNode(int* tree, int ss, int se, int i, int increment, int index){// i->index in array a where you want to make the updateNode, index-> index of the current node we are on to in the segment tree, ss and se->start and end indexes of the range of the current node
    //case where i is out of bounds
    if(i<ss || i>se){
        return;
    }
    //leaf node {comes after the above case, so we can be sure we are at the correct leaf node}
    if(ss == se){
        tree[index] += increment;
        return;
    }
    //otherwise
    int mid = (ss+se)/2;
    updateNode(tree,ss,mid,i,increment,2*index);
    updateNode(tree,mid+1,se,i,increment,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);

}

void updateRange(int* tree, int ss, int se, int l, int r, int inc, int index){//l,r->start and end of the range you want to update
    //out of bounds
    if(l>se || r<ss){//this case must come before the next case
        return;
    }
    //leaf node
    if(ss == se){//no need to check if in range l-r since above case already handles it
        tree[index] += inc;
        return;
    }

    //recursive case
    int mid = (ss + se)/2;
    updateRange(tree, ss, mid, l, r, inc, 2*index);
    updateRange(tree, mid, se, l, r, inc, 2*index+1);

    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

int main(){

    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a)/sizeof(int);

    int* tree = new int[4*n+1];
    buildTree(a,0,n-1,tree,1);

    // //lets also print the tree array
    // for(int i=1;i<=13;i++){
    //     cout<<tree[i]<<" ";
    // }

    //update
    updateNode(tree,0,n-1,3,+10,1);

    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(tree, 0, n-1, l, r, 1)<<endl;
    }

    return 0;
}