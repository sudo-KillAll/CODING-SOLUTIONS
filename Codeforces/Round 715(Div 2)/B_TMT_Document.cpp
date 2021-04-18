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
    ll n;cin>>n;
    string s;cin>>s;
    vi a(n,0),b(n,0);
    if(s[0]=='T')   a[0]++;
    for(ll i=1;i<n;i++){
        a[i] = a[i-1];
        if(s[i]=='T')   a[i]++;
    }
    if(s[0]=='M')   b[0]++;
    for(ll i=1;i<n;i++){
        b[i] = b[i-1];
        if(s[i]=='M')   b[i]++;
    }

    for(ll i=0;i<n;i++){
        if(s[i]=='M'){
            //
            if(a[i]-b[i]<0){
                //cout<<a[i]<<" "<<b[i]<<"\n";
                cout<<"NO\n";
                return;
            }
        }
    }

    vi c(n,0),d(n,0);
    if(s[n-1]=='T')   c[n-1]++;
    else    d[n-1]++;
    for(ll i=n-2;i>=0;i--){
        c[i] = c[i+1];
        d[i] = d[i+1];
        if(s[i]=='T')   c[i]++;
        else    d[i]++;
    }

    for(ll i=n-1;i>=0;i--){
        if(s[i]=='M'){
            if(c[i]-d[i]<0){
                //cout<<c[i]<<" "<<d[i]<<"\n";
                cout<<"NO\n";
                return;
            }
        }
    }
    if(a[n-1]!=(b[n-1]*2))  cout<<"NO\n";
    else
        cout<<"YES\n";

}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase
solve();
} 