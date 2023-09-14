//https://www.spoj.com/problems/HOLI/
//See video to understand the solns and also read the follwing two small articles:
//https://codeforces.com/blog/entry/8149
//http://zobayer.blogspot.com/2014/01/spoj-holi.html

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class graph{

    int V;//number of vertices
    list<pair<int,int>> *l;//adjacency list of the graph

public:
    graph(int v){//graph receives the number of vertices
        V = v;
        l = new list<pair<int,int>>[V];//sir-> it is an array of v linked lists
    }

    void addEdge(int u, int v, int cost){
        l[u].push_back(make_pair(v,cost));
        l[v].push_back(make_pair(u,cost));
    }

    ll dfs_helper(int node, bool *vis, ll* count, ll &ans){//returns the count of nodes in the subgraph starting from that node
        //mark the node visited
        vis[node] = true; 
        count[node] = 1;
        for(auto nbr_pair : l[node]){
            int nbr = nbr_pair.first;
            ll wt = nbr_pair.second;
            if(!vis[nbr]){
                count[node] += dfs_helper(nbr,vis,count,ans); 
                ll nx = count[nbr];
                ll ny = V-nx; 
                ans += 2 * min(nx,ny) * wt;        
            }
        }
        //just before returning from the current node
        return count[node];
    }

    ll dfs(){
        bool* vis = new bool[V];//visited array
        ll* count = new ll[V]; 

        for(int i=0; i<V; i++){
            vis[i] = false;
            count[i] = 0;
        }

        ll ans = 0;//total distance travelled
        dfs_helper(0,vis,count,ans);
        return ans; 
    }
    
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    for(int i=1; i<=t;i++){
        int n;
        cin>>n;
        graph g(n);
        for(int j=0; j<n-1; j++){
            int x,y,z;
            cin>>x>>y>>z;
            g.addEdge(x-1,y-1,z);
        }
        cout<<"Case #"<<i<<": "<<g.dfs()<<endl;
    }


    return 0;
}