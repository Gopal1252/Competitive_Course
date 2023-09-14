//https://codeforces.com/problemset/problem/276/D
//https://hack.codingblocks.com/app/practice/5/997/problem
#include<bits/stdc++.h>
using namespace std;

#define ll long long
//solution:https://github.com/satyajeetkrjha/solution-codeforces/blob/master/Codeforces%20Round%20%23169%20(Div.%202)%2C%20problem:%20(D)%20Little%20Girl%20and%20Maximum%20XOR%2C%20Accepted%2C%20%23
//see video to understand the idea and then this solution on github and it;s explanation on quora(link in github solution)
//basically find the leftmost set bit in the XOR of a,b. Let the location of this set bit be i(1-indexed)
//Then answer is (1<<i)-1 ;

/* FROM QUORA
Though a brute force solution will pass, It will run with complexity O(n^2). The answer you have posted will run in O( log(n) ) .
Before going into the problem take a few examples of L , R and try to solve them .

eg : L = 1 , R = 9
Binary representation 1 , 1001 . we need the last xor bit of L and R that is '1' . In this case xor of 1001 , 1 = 1000 . last '1' xor bit is at 4th position . 
We can fill All position < 4 to 1 . so the max value that we can get is 1111 .

Lets do it for L = 10, R = 11
1010 ^ 1011 = 0001. Last xor is at first position . Max value we can get is 1

for L = 8 R = 36

1000 ^ 100100 = 101100 . Last 1 is at position 6. Fill Positions with < 6 to 1 . Hence answer = 111111

This is what the code does. Note that x>>1 is equivalent to x/2 and 1<<x is equivalent to x*2 .
*/
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll a,b;
    cin>>a>>b;

    ll XOR = a^b;
    ll x = 1;

    while(x<=XOR){
        x = (x<<1);
    }
    cout<<x-1<<endl;

    return 0;
}