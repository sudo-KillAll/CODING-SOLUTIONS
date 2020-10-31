/*Problem : 
    Given An array of n integers , every integer in array occurs twice except 2 elements which
    occurs only once,Find these single occuring numbers.
*/

/*
Approach:
    1) First find the xor of all Numbers of array, Let x;
    2) find position any set bit of x , for sake of simplicity we took Rightmost set bit.Let y;
    3) Initialize num1 and num2 as zero.
    4) Now traverse the array and check yth bit of A[i],
    if(A[i]==1)
        num1=num1^A[i]
    if(A[i]==0)
        num2=num2^A[i];

    "The idea is that if we do this way then array will be partitioned into 2 parts ,
    where 1 part will contain the numbers with yth bit set,and 2nd part numbers will have yth bit
    not set.This way if we xor each parts independently then we'll get answer for each part."

    5) num1 and num2 are required answer.
*/


#include<bits/stdc++.h>

#define ll long long int
#define vi vector<ll>
#define mi map<ll,ll>
#define pb push_back
#define test ll testcase;cin>>testcase;while(testcase--)
using namespace std;
void solve(){

    ll n,xor_array=0;cin>>n;
    vi arr;
    for(ll i=0;i<n;i++){ll temp;cin>>temp;arr.pb(temp);xor_array^=temp;}
    //cout<<"Hello";

    ll right_most_set_bit=(ll)log2(xor_array & -xor_array);
    //cout<<right_most_set_bit;
    ll num1=0,num2=0;
    for(ll i=0;i<n;i++){
        ll power=pow(2,right_most_set_bit);
        ll bit_at_posn=(power)&(arr[i]);
        if(bit_at_posn==1)
            num1^=arr[i];
        else
            num2^=arr[i];
    }
    cout<<num1<<"  "<<num2;
}



using namespace std;
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
 solve();
}