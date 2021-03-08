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

bool solve(){
    ll n,m;cin>>n>>m;
    vs v(n);
    FOR(i,0,n) cin>>v[i];
    vector<pair<ll,ll>> vp;
    FOR(i,0,n){
        ll f=INT_MAX,s=INT_MIN,firsInd=-1;
        FOR(j,0,m){
            if(v[i][j]=='1'){
                firsInd=j;
                break;
            }
        }
        if(firsInd!=-1){
            FOR(j,firsInd,m){
                if(v[i][j]=='1'){
                    f=min(f,j);
                    s=max(s,j);
                }
                else 
                    break;
            }
            if(f!=INT_MAX){
                FOR(j,0,f){
                    if(v[i][j]=='1')
                        return false;
                }
                FOR(j,s+1,m){
                    if(v[i][j]=='1')
                        return false;
                }
            }
        }
        
        pair<ll,ll> p(f,s);
        vp.pb(p);  
    }
    ll f,s,i=0,cnt=0;
    while(i<vp.size()){
        pair<ll,ll> p=vp[i];
        if(cnt>1)
            return false;
        //bool found = false;
        ll j=i;
        if(p.F!=INT_MAX){
            cnt++;
            f=p.F;s=p.S;
            
            while(j<vp.size()){
                pair<ll,ll> q=vp[j];
                if(q.F==INT_MAX)
                    break;
                if(q.F!=f || q.S!=s)
                    return false;
                j++;
            }
        }
        i=j+1;

    }
    if(cnt>1)
        return false;
    return true;

}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase{
    solve()==true?cout<<"YES\n":cout<<"NO\n";
}
} 