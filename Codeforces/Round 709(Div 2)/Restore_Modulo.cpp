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
    ll n;cin>>n;
    vi v;input(v,n);
    bool found=false;
    for(ll i=0;i<n;i++){
        if(v[i]!=v[0]){
            found=true;
            break;
        }
    }
    if(!found || n==1){
        cout<<"0\n";
        return;
    }

    ll maxi = maxv(v);
    ll ind;
    for(ll i=0;i<n;i++){
        if(v[i]==maxi){
            ind=i;
            break;
        }
    }
    ll c=-1,m=-1;
    if(ind==0){
        c=v[0]-v[1];
        for(ll i=1;i<n;i++){
            if(v[i-1]-v[i]!=c){
                cout<<"-1\n";
                return;
            }
        }
        cout<<"0\n";
    }
    else if(ind==n-1){
        c=v[ind]-v[ind-1];
        for(ll i=1;i<n;i++){
            if(v[i]-v[i-1]!=c){
                cout<<"-1\n";
                return;
            }
        }
        cout<<"0\n";
    }
    else{
        c=v[ind]-v[ind-1];
        for(ll i=1;i<ind;i++){
            if(v[i]-v[i-1]!=c){
                cout<<"-1\n";
                return;
            }
        }
        ll m = c+v[ind]-v[ind+1];
        for(ll i=ind+1;i<n;i++){
            if((v[i-1]+c)%m!=v[i]){
                cout<<"-1\n";
                return;
            }
        }
        cout<<m<<" "<<c<<"\n";
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