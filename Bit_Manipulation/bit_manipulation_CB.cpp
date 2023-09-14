#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n){
    return (n & 1);
}

int getBit(int n, int i){ // to get the ith bit of number n
    int mask = (1<<i);
    return (n & mask) > 0 ? 1 : 0;
}

int setBit(int n, int i){//to set ith bit of a given number n
    int mask = (1<<i);
    int ans = (n | mask);
    return ans;
}

void clearBit(int &n, int i){// to unset ith bit of a given number n
    int mask = ~(1<<i);
    n = (n & mask);
}

void updateBit(int &n, int i, int v){// to set the ith bit of a given number n to v(0 or 1)
    n = (n & (~(1<<i)));//clear the ith bit
    int mask = (v<<i);//make a mask with v as ith bit
    n = (n | mask);
}

int clearLastIBits(int n, int i){//to clear last bits till ith position of a given number n
    int mask = (-1 << (i+1));
    return (n & mask);
}

int clearRangeItoJ(int n, int i, int j){//to clear a range of bits from ith to jth position of a given number n
    int ones = (~0);
    int a = (ones<<(j+1));
    int b = (1<<i)-1;
    int mask = (a|b);
    int ans = (n & mask);
    return ans;
}

int  main(){

    
    return 0;
}