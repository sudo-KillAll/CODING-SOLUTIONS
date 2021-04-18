/*
``````````````````$$$$$
`````````````$$$$$$´´´´$$$$$$
``````````$$$´´´´´´´´´´´´´´´´$$$
````````$`$$´´´´´´´´´´´´´´´´´´´´$$
```````$´$$$´´´´´´´´´´´´´´´´´´´´´$$$$
`````$´´$$$$´´´´´´´´´´´´´´´´´´´´´´´´´´$
````$´´$$$$$´´´´´´´´´´$$$$$$$´´´´´´´´´$$
```$´´´$$$$$$$´´´$$$$$$$$$$$$$$$$$´´´´´$$
``$´´´´$$$$$$$$$$$$$$$$$$$$$$$$$$$$$´´´´$$
`$´´´´´´$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$´´$
`$´´´´´´$$$$$$$$$$$´´´´$$$$$$$$$$$$$$$$$$$
$´´´´´´´´$$$$$$$$´´´´´´´´$$$$$$$´´´´´´´´$$
$´´´´´´´´´$$$$$$´´´´´´´´´´$$$$´´´´´´´´´´´$
`$´´´´´´´´´$$$$$´´´´´´´´´´$$$´´´´´´´´´´´$
`$´´´´´´´´´´$$$$$´´´´´´´´$$$$´´´´´´´´´´´$
`$´´´´´´´´´´´$$$$$$´´´´$$$$$´´´´´´´´´´´$$
``$´´´´´´´´´´´$$$$$$$$$$$$$$´´´´´´´´´´´$
``$$´´´´´´´´´´´´$$$$$$$$$$$$´´´´´´´´´´$$
```$$´´´´´´´´´´´´$$$$$$$$$$´´´´´´´´´´$$
````$´´´´´´´´´´´´$$$$$$$$$´´´´´´´´´´´$
`````$´´´´´´´´´´´$$$$$$$$´´´´´´´´´´´$
``````$$´´´´´´´´´$$$$$$´´´´´´´´´´´$$
````````$$´´´´´´$$$$$´´´´´´´´´´´$$
``````````$$$´$$$$´´´´´´´´´´´$$$
`````````````$$$$$´´´´´´$$$$$
``````````````````$$$$$$
*/
#include "bits/stdc++.h"
 
#define ll long long int
#define pb push_back
#define F first
#define S second
#define vi vector<ll>
#define vs vector<string>
#define input(v,n) for(ll VAL=0;VAL<n;VAL++){ll VALUE;cin>>VALUE;v.pb(VALUE);}
#define mi map<ll,ll>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define mi map<ll,ll>
#define print(v) for(ll printing=0;printing<v.size();printing++){cout<<v[printing]<<' ';}
#define TestCase ll testcase;cin>>testcase;while(testcase--)
#define bin(n) bitset<32>(n).to_string();
#define maxv(v) *max_element(v.begin(),v.end())
#define minv(v) *min_element(v.begin(),v.end())
#define decimal(s) stoll(s,nullptr,2)
#define rmLead(str) str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
using namespace std;

void solve(){
    ll a,b;cin>>a>>b;
    string s;cin>>s;
    ll n=s.length();
    for(ll i=0;i<n;i++){
        if(s[i]=='0')
            a--;
        else if(s[i]=='1')
            b--;
    }
    if(a<=0 && b<=0){
        cout<<"-1\n";
        return;
    }
    for(ll i=0;i<n/2;i++){
        if(s[i]!='?' && s[n-i-1]!='?'){
            if(s[i]==s[n-i-1]){
                if(s[i]=='0')
                    a--;
                else
                    b--;
            }
            else{
                cout<<"-1\n";
                return;
            }
        }
        else if(s[i]!='?' || s[n-i-1]!='?'){
            if(s[i]!='?'){
                s[n-i-1]=s[i];
                if(s[i]=='0')
                    a--;
                else
                    b--;
            }
            else{
                s[i]=s[n-i-1];
                if(s[n-i-1]=='0')
                    a--;
                else
                    b--;
            }
        }
    }
    
    if(a%2!=0 && b%2!=0){
        cout<<"-1\n";
        return;
    }
    for(ll i=0;i<n/2;i++){
        if(s[i]=='?'){
            if(a>=2){
                s[i]='0';
                s[n-i-1]='0';
                a-=2;
            }
            else if(b>=2){
                s[i]='1';
                s[n-i-1]='1';
                b-=2;
            }
            else{
                cout<<"-1\n";
                return;
            }
        }
    }
    if(n%2!=0){
        if(s[n/2]=='?'){
            if(a>0){
                s[n/2]='0';
                a--;
            }
            else if(b>0){
                s[n/2]='1';
                b--;
            }
            else{
                cout<<"-1\n";
                return;
            }
        }
    }
    ll cnt=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='?')
            cnt++;
    }
    if(a>0 || b>0){
        cout<<"-1\n";
        return;
    }
    cout<<s<<"\n";
}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase
solve();
} 