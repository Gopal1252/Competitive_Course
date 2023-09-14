//code to find MSB 
#include<bits/stdc++.h>
using namespace std;

//dry run for finding msb of 1, you will understand the code

int main(){
    int n;
    cin>>n;

    int msb = 0;

    n = n/2;

    while(n != 0){
        n = n/2;
        msb++;
    }

    cout<<"MSB or the highest power of 2 less than n: "<<(1<<msb);
 
    return 0;
}