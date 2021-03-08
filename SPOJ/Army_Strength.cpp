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
void solve(){
ll n,m;cin>>n>>m;
vi a,b;
forn(n){ll x;cin>>x;a.pb(x);}
forn(m){ll x;cin>>x;b.pb(x);}
sort(a.begin(),a.end());
sort(b.begin(),b.end());
ll i=0,j=0;
ll c1=0,c2=0;
while(i<n && j<m){
    if(a[i]<b[j]){c2++;i++;}
    else if(a[i]==b[j]){c1++;j++;}
    else{c1++;j++;}
}
c1+=n-i-1;
c2+=m-j-1;
 if(c1>=c2)
    cout<<"Godzilla"<<"\n";
else
    cout<<"MechaGodzilla"<<"\n";

}

int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase
    solve();
}