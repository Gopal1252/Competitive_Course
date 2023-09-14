//https://hack.codingblocks.com/app/practice/5/1264/problem
//In pirated Course, problem name->not so easy maths
//solution is in the Inclusion-Exclusion Principle Video {notes made in bitmanipulation register} 
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll t;
    cin>>t;

    ll primes[] ={2,3,5,7,11,13,17,19};

    while(t--){
        ll n;
        cin>>n;

        ll subsets = (1<<8) -1; //since number of primes<20 = 8, number of of subsets = 2^8-1(since not taking the case where all the digits are zero)
        ll ans = 0;
        for(ll i = 1;i<=subsets;i++){
            ll denom = 1ll; //denominator (1ll means 1 but as a long long integer)
            ll setBits = __builtin_popcount(i);//number of set bits

            for(ll j=0;j<=7;j++){
                if(i & (1<<j)){
                    denom = denom * primes[j];
                }
            }
            if(setBits&1){//checking if setBits is odd 
                ans += n/denom;
            }
            else{
                ans -= n/denom;
            }
        }    
        cout<<ans<<endl;
    }

    return 0;
}