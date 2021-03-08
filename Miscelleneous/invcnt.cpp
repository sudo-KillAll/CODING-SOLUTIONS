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
 
using namespace std;
ll cnt;
 
void merge(vi &v,ll l,ll m,ll r){
    ll i=l,j=m+1;
    vector<ll> a;
    
    while(i<=m && j<=r){
        if(v[i]<=v[j]){a.pb(v[i]);i++;}
        //else if(v[i]==v[j]){a.pb(v[i]);a.pb(v[j]);i++;j++;}
        else{a.pb(v[j]);j++;cnt+=m-i+1;}
    }
 
    while(i<=m){a.pb(v[i]);i++;}
    while(j<=r){a.pb(v[j]);j++;cnt+=m-i+1;}
    j=0;
    for(i=l;i<=r;i++){
        v[i]=a[j];j++;
    }
}
 
 
void mergeSort(vi &v,ll l,ll r){
    if(l>=r)
        return;
    ll m=l+(r-l)/2;
    mergeSort(v,l,m);
    mergeSort(v,m+1,r);
    merge(v,l,m,r);

}
 
void solve(){
    cnt=0;
    ll n;cin>>n;
    vi v;
    for(ll i=0;i<n;i++){ll temp;cin>>temp;v.pb(temp);}
    mergeSort(v,0,n-1);
    cout<<cnt<<"\n";
 
}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
ll t;cin>>t;
 
while(t--){
    solve();
    //cin>>x;
}
    
} 