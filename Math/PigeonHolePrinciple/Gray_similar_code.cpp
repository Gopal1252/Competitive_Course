//https://www.codechef.com/problems/GRAYSC
#include<bits/stdc++.h>
using namespace std;

int main(){

	unsigned long long n;
	vector<unsigned long long> v;

	cin>>n;

	for(int i=0;i<n;i++){
		unsigned long long no;
		cin>>no;
		if(n<130){
			v.push_back(no);
		}
	}

	
	if(n>=130){
		cout<<"Yes";
		return 0;
	}
	//Brute force for small values
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		   for(int k=j+1;k<n;k++){
			for(int l=k+1;l<n;l++){
					if((v[i]^v[j]^v[k]^v[l])==0){
						cout<<"Yes"<<endl;
						return 0;
					}

				}
			}
		}
	}
	cout<<"No";


	return 0;
}