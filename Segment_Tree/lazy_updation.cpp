#include<bits/stdc++.h>
using namespace std;

int lazy[10000] = {0};//initially lzy value of all the nodes = 0

void updateRangeLazy(int* tree, int ss, int se, int l, int r, int inc, int index){//l,r->range of update, ss,se->range of segment tree node
    //before going down, resolve the lazy value if it exists {i.e -> lazy != 0} 
    if(lazy[index] != 0){
        tree[index] += lazy[index];//update the current node's value
        //non leaf node
        if(ss != se){//if current node is not a leaf, then we pass the lazy value to it's children
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;//cear the lazy value at the current nde
    }
    //Base case {i.e no overlap case}
    if(ss>r || se<l){
        return;
    }

    //another case ->complete overlap
    if(ss>=l && se<=r){
        tree[index] += inc;

        //create a new lazy value for the children (if it has children, i.e it is not a leaf node)
        if(ss != se){
            lazy[2*index] += inc;
            lazy[2*index+1] += inc;
        }
        return;//not making any recursive calls on left and right children since this is lazy update {optimization}
    }

    //recursive case ->partial overlap
    int mid = (ss+se)/2;
    updateRangeLazy(tree, ss, mid, l, r, inc, 2*index);
    updateRangeLazy(tree, mid+1, se, l, r, inc, 2*index+1);
    //update the tree[index]
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

int queryLazy(int* tree, int ss, int se, int qs, int qe, int index){
    //resolve the lzy value at the current node
    if(lazy[index] != 0){
        tree[index] += lazy[index];//update the current node's value
        //non leaf node
        if(ss != se){//if current node is not a leaf, then we pass the lazy value to it's children
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        lazy[index] = 0;//cear the lazy value at the current nde
    }
    //Query logic

    //No Overlap
    if(ss>qe || se<qs){
        return INT_MAX;//returning INT_MAX in case of range minimum query question
    }

    //complete overlap
    if(ss>=qs && se<=qe){
        return tree[index];
    }

    //partial overlap (make calls on left and right children)
    int mid = (ss+se)/2;
    int left = queryLazy(tree,ss,mid,qs,qe,2*index);
    int right = queryLazy(tree,mid+1,se,qs,qe,2*index+1);
    return min(left,right);
}

//same as segment tree basics
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

int main(){
    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a)/sizeof(int);

    int* tree = new int[4*n+1];
    buildTree(a,0,n-1,tree,1);

    updateRangeLazy(tree,0,n-1,0,2,10,1);
    updateRangeLazy(tree,0,n-1,0,4,10,1);
    cout<<"Q1 1-1 "<<queryLazy(tree,0,n-1,1,1,1)<<endl;
    updateRangeLazy(tree,0,n-1,3,4,10,1);
    cout<<"Q2 3-5 "<<queryLazy(tree,0,n-1,3,5,1)<<endl;

    return 0;
}