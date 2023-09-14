//https://www.spoj.com/problems/SEQ/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000000

ll k;
vector<ll> a,b,c;

vector<vector<ll>> multiply(vector<vector<ll>> A,vector<vector<ll>> B){
    vector<vector<ll>> C(k+1, vector<ll>(k+1));
    //logic to multiply matrices
    for(int i=1; i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int x=1; x<=k; x++){
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j])%MOD)%MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> pow(vector<vector<ll>> T, ll p){// means power
    //base case
    if(p == 1){
        return T;
    }

    //if p is odd
    if(p&1){
        return multiply(T, pow(T ,p-1));
    }
    vector<vector<ll>> X = pow(T,p/2);
    return multiply(X,X); 
}

ll compute(ll n){

    //base case
    if(n == 0){
        return 0;
    }

    if(n <= k){
        return b[n-1];//b is given 1-indexed and we stored it 0-indexed
    }

    //otherwise use matrix exponentiation
    //step-1 : Build the F1 vector
    vector<ll> F1(k+1);//k+1 since we will do indexing from 1, but you can also do from 0
    for(int i=1; i<=k; i++){
        F1[i] = b[i-1];
    }

    //step-2 : Build the transformation matrix
    vector<vector<ll>> T(k+1, vector<ll>(k+1));//k+1 since we will do indexing from 1, but you can also do from 0
    for(int i=1; i<=k; i++){
       for(int j=1; j<=k; j++){
            if(i<k){//till i<k, we fill 0s and 1s
                if(j == i+1){
                    T[i][j] = 1;
                }
                else{
                    T[i][j] = 0;
                }
            }
            else{
                T[i][j] = c[k-j]; 
            }
       }  
    }

    //step-3 : Calulate the power of the transformation matrix
    T = pow(T, n-1);

    //step-4 : Multiply T^n-1 to F1 {Multiplication of matrix with vector}
    ll res = 0;
    for(int i=1; i<=k; i++){
        res = (res + (T[1][i]*F1[i])%MOD)%MOD;
    }
    return res; 
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t,n,num;
    cin>>t;
    while(t--){
        cin>>k;

        //input the F1 vector
        for(int i=0; i<k; i++){
            cin>>num;
            b.push_back(num);
        }

        //coefficients
        for(int i=0; i<k; i++){
            cin>>num;
            c.push_back(num);
        }

        //the value of n
        cin>>n;
        cout<<compute(n)<<endl;

        b.clear();
        c.clear();
    }

    return 0;
}