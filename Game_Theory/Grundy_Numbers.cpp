#include<bits/stdc++.h>
using namespace std;

//new trick:
//Atcoder Problem : https://atcoder.jp/contests/abc297/tasks/abc297_g
//Editorial : https://atcoder.jp/contests/abc297/editorial/6205
// Grundy Formula : (num%(l+r))/l 😮

int calculateMex(unordered_set<int> Set){
    int Mex = 0;
    while(Set.find(Mex) != Set.end()){
        Mex++;
    }

    return Mex;
}

//A function to compute grundy Number of 'n
//Only this function varies according to the game
int calculateGrundy(int n){
    if(n==0)
    return 0;

    unordered_set<int> Set; //A Hash Table

    for(int i=1;i<=n;i++){
        Set.insert(calculateGrundy(n-i));
    }

    return calculateMex(Set);
}

int main(){

    
    return 0;
}