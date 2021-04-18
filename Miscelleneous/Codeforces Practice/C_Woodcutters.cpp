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
#include <bits/stdc++.h>
 
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
    vector<pair<ll,ll>> vp;
    for(ll i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        pair<ll,ll> p(x,y);
        vp.pb(p);
    }

    if(n<=2){
        cout<<n;
        return;
    }
    ll ans=2;
    for(ll i=1;i<n-1;i++){
        ll coord = vp[i].F,height = vp[i].S;
        if(coord-height>vp[i-1].F){
            ans++;
        }
        else if(coord+height<vp[i+1].F){
            ans++;
            vp[i].F = coord+height;
        }
        else
            continue;
    }
    cout<<ans;

}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
solve();
} 