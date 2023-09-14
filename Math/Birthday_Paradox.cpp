#include<bits/stdc++.h>
using namespace std;

/*
What is the minimum number of people that
should be present in a room so that there’s 50%
chance of two people having same birthday?
*/

//Before that what should be no. of people for 100% probability for at least 2 people to have same bday?
//Answer->366 people

//If p = prob of 2 people having same bday
//then x = 1-p is prob of all people having different bday
//we will find x and then subtract from 1 for our answer

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    float x = 1.0;//x denotes the probability of all people having the different bday
    int people = 0;

    float num = 365;
    float denom = 365;

    float p;//{enter in fraction}the probability {of 2ppl having different bday}that the user wants {in above ques->50%}
    cin>>p;

    if(p == 1.0){//corner case, since the value of x becomes too small to be handled by float
        cout<<"No. of people required for the prob of 2 ppl having same bday to be equal to 100% is "<<"366"<<endl;
        return 0;
    }

    //as soon as x falls below 1-p,it means that 1-x(the required prob) has hit just above the required p
    while(x > 1-p){//as the loop progresses and np. of people increases, value of x decreases
        x = x*((num)/(denom));
        num--;
        people++;
    }
    cout<<"No. of people required for the prob of 2 ppl having same bday to be equal to "<<p*100<<"% is :"<<people<<endl;

    return 0;
} 