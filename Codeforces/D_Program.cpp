#include<bits/stdc++.h>
 
#define ll long long int
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define vs vector<string>
#define input(v,n) for(ll VAL=0;VAL<n;VAL++){ll VALUE;cin>>VALUE;v.pb(VALUE);}
#define mi map<ll,ll>
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define mi map<ll,ll>
#define print(v) for(ll printing=0;printing<v.size();printing++){cout<<v[printing]<<' ';}
#define TestCase ll testcase;cin>>testcase;while(testcase--)
#define bin(n) bitset<32>(n).to_string();
#define maxv(v) *max_element(v.begin(),v.end())
#define minv(v) *min_element(v.begin(),v.end())
#define decimal(s) stoll(s,nullptr,2)
using namespace std;

void solve(){

    ll n,q;cin>>n>>q;
    string s;cin>>s;
    vector<pair<ll,ll>> prefix,suffix;

    ll mini=0,maxi=0;
    ll x=0;
    pair<ll,ll> p;
    p=make_pair(mini,maxi);
    prefix.pb(p);

    for(auto i:s){
        i=='+'?x++:x--;
        mini=min(x,mini);
        maxi=max(x,maxi);
        p=make_pair(mini,maxi);
        prefix.pb(p);
    }
    x=0;
    mini=0,maxi=0;
    x=0;
    p=make_pair(mini,maxi);
    suffix.pb(p);
    for(ll i=n-1;i>=0;i--){
        s[i]=='+'?x++:x--;
        mini=min(x,mini);
        maxi=max(x,maxi);
        p=make_pair(mini,maxi);
        suffix.pb(p);
    }

    while(q--){
        ll l,r;cin>>l>>r;
        pair<ll,ll>fst=prefix[l],q=suffix[r];
        mini=min(fst.f,q.f);maxi=max(fst.s,q.s);
        cout<<maxi-mini<<"\n";
    }

}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase
    solve();
}