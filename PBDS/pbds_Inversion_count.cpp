//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1, but TLE happening
//so we do the above question by using merge sort
//https://leetcode.com/problems/reverse-pairs/ {similar}
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> 
        PBDS_distinct; //normal ordered set

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,
        tree_order_statistics_node_update> 
        PBDS_pair; //ordered set with type pair<int,int>


int main(){
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    PBDS_distinct st;
    PBDS_pair st2;

    int inversion_ct = 0;

    //when only distinct elements
    // for(int i=0;i<n;i++){
    //     inversion_ct += (st.size() - st.order_of_key(a[i]));
    //     st.insert(a[i]);
    // }
    // cout<<inversion_ct;

    // when elements repeated {can also use when distinct elements}
    for(int i=0;i<n;i++){
        inversion_ct += (st2.size() - st2.order_of_key({a[i],i}));
        st2.insert({a[i],i});
    }
    cout<<inversion_ct;

    


    return 0;
}