#include<bits/stdc++.h>
using namespace std;

void multiply(int *a , int &n, int no){//we have to multiply array a by no
    int carry = 0;
    for(int i=0;i<n;i++){
        int product = a[i]*no + carry;
        a[i] = product%10;
        carry = product/10;
    }

    while(carry){
        a[n] = carry%10;
        carry = carry/10;
        n++;
    }
}

void big_factorial(int num){
    int *a = new int[1000];//can store 1000 digits
    for(int i=0;i<1000;i++){
        a[i] = 0;
    }

    a[0] = 1;
    int n = 1;//no. of digits the array currently
    for(int i=2; i<=num;i++){
        multiply(a, n, i);
    }

    //print the result
    for(int i=n-1;i>=0;i--){
        cout<<a[i];
    }

    delete [] a;
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    big_factorial(n);

    return 0;
}