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

const ll N = 1e7;
vi spf(N+1);

void generate(){
    spf[0]=1;spf[1] = 1;
    bool marked[N+1] = {false};
    for(ll i=2;i*i<=N;i++){
        if(!marked[i]){
            marked[i] = true;
            spf[i] = i;
            for(ll j=i*i;j<=N;j+=i){
                if(!marked[j]){
                    marked[j] = true;
                    spf[j] = i;
                }
            }
        }
    }
    for(ll i=2;i<=N;i++){
        if(!marked[i])  spf[i] = i;
    }
}

vi ans(N+1);
map<ll,ll> mp;

void getAns(){
    for(ll i=2;i<=100000;i++){
        ll val = i;
        map<ll,ll> tmp;
        while(val!=1){
            tmp[spf[val]]++;
            val=val/spf[val];
        }
        ll s = 0;
        for(auto it=tmp.begin();it!=tmp.end();it++){
            ll a = it->F,b = it->S;
            s+=(pow(a,b+1)-1)/(a-1);
        }
        if(mp.find(s)!=mp.end()){
            mp[s] = min(mp[s],i);
        }
        else{
            mp[s] = i;
        }
    }
}

void solve(){

    ll x;cin>>x;
    if(x==1){
        cout<<"1\n";
        return;
    }
    if(mp.find(x)==mp.end()){
        cout<<"-1\n";
        return;
    }
    cout<<mp[x]<<"\n";

}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
generate();
getAns();
TestCase
solve();
} 