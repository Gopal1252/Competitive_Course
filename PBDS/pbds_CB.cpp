//Header Files

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//Including tree_order_statistics_node_update

using namespace __gnu_pbds;

//Declaration of tree-based container

template<
    //Key type
    typename Key, 

    //Mapper-policy
    typename Mapped, //null_type for set, Mapped for map

    //Key comparison functor (functor ->function object i.e a class that works like a function)
    typename Cmp_Fn = std::less<Key>,//basically the comparator

    //Specifies which underlying data structure to use
    typename Tag = rb_tree_tag,

    template<
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn_,
        typename Allocator_ >

    //A policy for updating node invariants
    class Node_Update = null_node_update,

    //An allocator type
    typename Allocator = std::allocator<char> 
>
class tree;


typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> 
        new_data_set; 


/*
Tree Structures
rb_tree_tag         (red-black tree)
splay_tree_tag      (splay tree)
ov_tree_tag         (ordered - vector tree)
*/

//Final Declaration that we will use :

typedef  tree <
int, 
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


//for more info:
//https://gcc.gnu.org/onlinedocs/libstdc++/manual/policy_data_structures.html

