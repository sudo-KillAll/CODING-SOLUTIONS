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
    ll n,k;cin>>n>>k;
    vi ans;
    for(ll i=1;i<=k;i++) ans.pb(i);
    if(n==k){
        //sort(ans.begin(),ans.end());
        print(ans);
        cout<<"\n";
    }
    else{
        vi v;
        loop(i,1,k+1) v.pb(i);
        ll val=k-1;
        for(ll i=0;i<n-k;i++){
            v.pb(val);
            val--;
        }
        mergeSort(v,0,n-1);
        //cout<<cnt;
        val=sqrtl(cnt)+1;
        //cout<<val;
        sort(ans.begin()+k-val,ans.end(),greater<int>());
        print(ans);
        cout<<"\n";

    }
}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase
    solve();
} 