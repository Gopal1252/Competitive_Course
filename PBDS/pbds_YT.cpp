#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    int q;
    cin>>q;
    oset<int> s;
    while(q--){
        int c;
        cin>>c;
        if(c==1){
            int t;
            cin>>t;
            s.insert(t);//inserts value t into the ordered set {ordered set means the items are stored in the order they are entered into the set (I)}
        }
        else if(c==2){
            int t;
            cin>>t;
            cout<<*s.find_by_order(t)<<"\n";//returns the element at index t
        }
        else{
            int t;
            cin>>t;
            cout<<s.order_of_key(t)<<"\n";//returns the number of elements smaller than t
        }
    }

    return 0;
}