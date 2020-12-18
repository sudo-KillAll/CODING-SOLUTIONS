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
void solve(){

    ll n;cin>>n;
    vi v;
    forn(n){ll temp;cin>>temp;v.pb(temp);}
    ll i=0,j=n-1,cnt=1;
    vi ans;
    while(i<=j){
        if(cnt%2==1){ans.pb(v[i]);i++;}
        else{ans.pb(v[j]);j--;}
        cnt++;
    }
    print(ans);
    cout<<"\n";

}

int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase
    solve();
}