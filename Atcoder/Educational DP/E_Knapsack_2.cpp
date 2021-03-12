#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,w;
    cin>>n>>w;
    vector<ll> v(n+1),wt(n+1);
    ll tot=0;
    for(int i=1;i<=n;++i){
        cin>>wt[i]>>v[i];
        tot+=v[i];
    }
    // cout<<tot<<endl;
    vector<vector<ll>> dp(n+1,vector<ll>(tot+1,10e11)); // dp[i][j] means min wt req to make value v when there r n items
    for(ll i=0;i<=n;++i)
        dp[i][0] = 0;
    for(ll i=1;i<=n;++i){
        for (ll j = 1; j <= tot; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if(v[i]<=j){
                // cout<<v[i]<<" "<<j<<endl;
                dp[i][j] = min(wt[i]+dp[i-1][j-v[i]],dp[i-1][j]);
            }
            
        }
    }
    ll ans=0;
        for(ll j=0;j <= tot;++j){
            if(dp[n][j]<=w){
                ans = max(ans,j);
            }
            // if(dp[i][j]!=10e11)
            // cout<<dp[i][j]<<"("<<i<<","<<j<<") ";
        }
    
    cout << ans << endl;
 
    return 0;
}