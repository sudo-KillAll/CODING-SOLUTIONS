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

    string x,y;cin>>x>>y;
    ll n=x.length(),m=y.length();
    ll dp[n+1][m+1];dp[0][0]=0;
    for(ll i=0;i<=n;i++){dp[i][0]=i;}
    for(ll j=0;j<=m;j++){dp[0][j]=j;}

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                ll a=dp[i-1][j],b=dp[i][j-1],c=dp[i-1][j-1];
                dp[i][j]=min(min(a,b),c)+1;
            }
        }
    }
    cout<<dp[n][m]<<"\n";


}

int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase
    solve();
}