#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define mi map<ll,ll>
#define forn(n) for(ll i=0;i<n;i++)
#define mi map<ll,ll>
#define print(v) for(ll printing=0;printing<v.size();printing++){cout<<v[printing]<<' ';}
#define TestCase ll testcase;cin>>testcase;while(testcase--)
#define bin(n) bitset<32>(n).to_string();
using namespace std;
ll solve(){

    ll n,k;cin>>n>>k;
    vi v;
    v.pb(-1);
    forn(k){ll temp;cin>>temp;v.pb(temp);}
	//print(v);
    vi ans;
    for(ll i=0;i<=k;i++)
        ans.pb(INT_MAX);
    
    for(ll i=0;i<=k;i++){
        if(v[i]!=-1){
            ans[i]=v[i];
        }
    }
    //print(ans);
    for(ll i=1;i<=k;i++){
        for(ll j=0;j<k;j++){
            if(v[j]!=-1){
                if(i-j>=0){
                    ans[i]=min(ans[i],ans[i-j]+v[j]);
                }
                
            }
        }
    }
    //cout<<"Hello";
    return ans[k]==2147483647?-1:ans[k];



}

int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase
    cout<<solve()<<"\n";
}