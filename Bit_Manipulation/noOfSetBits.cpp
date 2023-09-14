#include<bits/stdc++.h>
using namespace std;

//built in fxn: __builtin_popcount(num) //TC:O(no. of set bits in num) or O(log(n)) {were n is the number}

//first method
int countBits(int n){
    int count = 0;
    while(n > 0){
        count+= (n&1);
        n = (n>>1);
    }
    return count;
}
//TC: O(logN)  where N is the integer number passed to the function, since in worst case, an integer N can have at max (logN + 1) bits

//second method(much faster)
int countBitsFast(int n){
    int ans = 0;
    while(n>0){
        n = (n&(n-1)); //this line removes the last set bit(try yourself with examples, will make sense)
        ans++;
    }
    return ans;
}
//TC:  O(Number of set bits in the number)
//     in worst case, number of set bits can be log(N)

int main(){
    return 0;
}