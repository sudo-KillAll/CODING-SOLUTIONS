#include<bits/stdc++.h>
#define ll long long int
#define MAX ll 1000000000000
#define gcd __gcd
#define vi vector<ll>
#define mi map<ll,ll>
#define pb push_back
#define print(v) for(ll i=0;i<v.size();i++)cout<<v[i]<<" ";
#define testcase ll testcase;cin>>testcase;while(testcase--)
using namespace std;

string solve(){
    ll n,m;cin>>n>>m;
    if(m!=(n-1))
        return "NO";
    mi edge;
    for(ll i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        edge[y]++;
    }
    ll cnt=0;
    for(auto it=edge.begin();it!=edge.end();it++){
        if(it->second == 0 && cnt!=0)
            return "NO";
        else if(it->second == 0 && cnt==0)
            cnt++;
        if(it->second > 1)
            return "NO";
    }
    return "YES";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //testcase
        cout<<solve();
}