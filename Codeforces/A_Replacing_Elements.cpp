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

string solve(){
    ll n,d;cin>>n>>d;
    vi v;input(v,n);

    for(ll i=0;i<n-1;i++){
        for(ll j=i+1;j<n;j++){
            if(v[i]+v[j]<=d)
                return "YES";
        }
    }
    ll val=maxv(v);
    if(val<=d)
        return "YES";
    return "NO";

}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase
    cout<<solve()<<"\n";
}