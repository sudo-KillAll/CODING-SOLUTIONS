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
#define test ll testcase;cin>>testcase;while(testcase--)

using namespace std;
void merge(vector<ll> &arr,ll l,ll m,ll r){
    ll i=l,j=m+1;
    vector<ll> a;
    
    while(i<=m && j<=r){
        if(arr[i]<arr[j]){a.pb(arr[i]);i++;}
        else if(arr[i]==arr[j]){a.pb(arr[i]);a.pb(arr[j]);i++;j++;}
        else{a.pb(arr[j]);j++;}
    }

    while(i<=m){a.pb(arr[i]);i++;}
    while(j<=r){a.pb(arr[j]);j++;}
    j=0;
    for(i=l;i<=r;i++){
        arr[i]=a[j];j++;
    }

}

void mergeSort(vector<ll> &arr,ll l,ll r){
    if(l>=r)
        return;
    ll m=l+(r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);

}


void solve(){

    ll n;cin>>n;
    vi arr;
    forn(n){
        ll x;cin>>x;arr.pb(x);
    }
    mergeSort(arr,0,n-1);
    print(arr);



}



using namespace std;
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
solve();
}