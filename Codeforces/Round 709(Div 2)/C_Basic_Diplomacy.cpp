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
#include<bits/stdc++.h>
 
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

    vi ans;
    ll n,m;cin>>n>>m;
    map<vi,ll> mp;
    map<ll,vi> mp2;
    for(ll i=0;i<m;i++){
        ll f;cin>>f;
        vi v;input(v,f);
        sort(v.begin(),v.end());
        mp[v]++;
        mp2[i]=v;
    }
    map<ll,ll> tmp;
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->S>((m+1)/2) && (it->F).size()==1){
            cout<<"NO\n";
            return;
        }
        for(ll i=0;i<it->S;i++){
            ans.pb(it->F[0]);
            tmp[it->F[0]]++;
        }
        
    }
    ll i=0;
    ll maxi=-1,val=-1;
    bool found=false;
    for(auto it=tmp.begin();it!=tmp.end();it++){
        if(it->S>((m+1)/2)){
            val=it->F;
            found=true;
            break;
        }
    }
    if(!found){
        cout<<"YES\n";
        print(ans);
        cout<<"\n";
    }
    else{
        ll ind=-1;
        for(ll i=0;i<n;i++){
            if(ans[i]==val){
                ind=i;
                break;
            }
        }
        ll cnt=tmp[val];
        while(cnt>((m+1)/2) && ind<m){
            if(mp2[ind].size()>=2){
                ans[ind]=mp2[ind][1];
                cnt--;
            }
            ind++;
        }
        if(cnt>((m+1)/2)){
            cout<<"NO\n";
            return;
        }
        

        cout<<"YES\n";
        print(ans);
        cout<<"\n";
    }



}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase{
    solve();
}
} 