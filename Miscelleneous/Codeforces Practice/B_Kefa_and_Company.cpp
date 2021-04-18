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
    ll n,d;cin>>n>>d;
    vector<pair<ll,ll>> vp;
    for(ll i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        pair<ll,ll> p(x,y);
        vp.pb(p);
    }
    sort(vp.begin(),vp.end());
    vi pref(n);
    pref[0] = vp[0].S;
    for(ll i=1;i<n;i++){
        pref[i] = pref[i-1]+vp[i].S;
    }
    vi v;
    for(ll i=0;i<n;i++) v.pb(vp[i].F);
    ll ans = pref[0];
    for(ll i=0;i<n;i++){
        auto it = lower_bound(v.begin(),v.end(),v[i]+d)-v.begin();
        if(i==0){
            ans = max(ans,pref[it-1]);
        }
        else{
            ans = max(ans,pref[it-1]-pref[i-1]);
        }
        //cout<<i<<" "<<it<<"\n";
        
    }
    cout<<ans;

}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
solve();
} 