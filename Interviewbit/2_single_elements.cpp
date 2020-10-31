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