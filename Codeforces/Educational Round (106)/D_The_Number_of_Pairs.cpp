/*
``````````````````$$$$$
`````````````$$$$$$´´´´$$$$$$
``````````$$$´´´´´´´´´´´´´´´´$$$
````````$`$$´´´´´´´´´´´´´´´´´´´´$$
```````$´$$$´´´´´´´´´´´´´´´´´´´´´$$$$
`````$´´$$$$´´´´´´´´´´´´´´´´´´´´´´´´´´$
````$´´$$$$$´´´´´´´´´´$$$$$$$´´´´´´´´´$$
```$´´´$$$$$$$´´´$$$$$$$$$$$$$$$$$´´´´´$$
``$´´´´$$$$$$$$$$$$$$$$$$$$$$$$$$$$$´´´´$$
`$´´´´´´$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$´´$
`$´´´´´´$$$$$$$$$$$´´´´$$$$$$$$$$$$$$$$$$$
$´´´´´´´´$$$$$$$$´´´´´´´´$$$$$$$´´´´´´´´$$
$´´´´´´´´´$$$$$$´´´´´´´´´´$$$$´´´´´´´´´´´$
`$´´´´´´´´´$$$$$´´´´´´´´´´$$$´´´´´´´´´´´$
`$´´´´´´´´´´$$$$$´´´´´´´´$$$$´´´´´´´´´´´$
`$´´´´´´´´´´´$$$$$$´´´´$$$$$´´´´´´´´´´´$$
``$´´´´´´´´´´´$$$$$$$$$$$$$$´´´´´´´´´´´$
``$$´´´´´´´´´´´´$$$$$$$$$$$$´´´´´´´´´´$$
```$$´´´´´´´´´´´´$$$$$$$$$$´´´´´´´´´´$$
````$´´´´´´´´´´´´$$$$$$$$$´´´´´´´´´´´$
`````$´´´´´´´´´´´$$$$$$$$´´´´´´´´´´´$
``````$$´´´´´´´´´$$$$$$´´´´´´´´´´´$$
````````$$´´´´´´$$$$$´´´´´´´´´´´$$
``````````$$$´$$$$´´´´´´´´´´´$$$
`````````````$$$$$´´´´´´$$$$$
``````````````````$$$$$$
*/
#include<bits/stdc++.h>
 
#define ll long long int
#define pb push_back
#define F first
#define S second
#define vi vector<ll>
#define vs vector<string>
#define input(v,n) for(ll VAL=0;VAL<n;VAL++){ll VALUE;cin>>VALUE;v.pb(VALUE);}
#define mi map<ll,ll>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define mi map<ll,ll>
#define print(v) for(ll printing=0;printing<v.size();printing++){cout<<v[printing]<<' ';}
#define TestCase ll testcase;cin>>testcase;while(testcase--)
#define bin(n) bitset<32>(n).to_string();
#define maxv(v) *max_element(v.begin(),v.end())
#define minv(v) *min_element(v.begin(),v.end())
#define decimal(s) stoll(s,nullptr,2)
#define rmLead(str) str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
using namespace std;

#define MAXN 10000001
 
// Stores smallest prime factor for every number
ll spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)
        spf[i] = i;
    for (ll i=2; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (ll j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not 
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
// A O(nlog n) function returning distinct primefactorization 
// upto n natural number by dividing by smallest prime factor 
// at every step
ll getdistinctFactorization(ll n)
{
    if(n<=1)
        return 0;
    set<ll> st;
    while(n!=1){
        st.insert(spf[n]);
        n=n/spf[n];
    }
    return st.size();
}



ll countPairs(ll G, ll L) 
{ 
    if (L % G != 0) 
       return 0; 
  
    ll div = L/G; 
  
    // answer is 2^totalPrimeFactors(L/G) 
    if(L==G){
        return 1;
    }
    ll val = getdistinctFactorization(div);
    return (1 << val); 
}
void solve(){

    ll c,d,x;
    cin>>c>>d>>x;
    ll ans=0;
    set<pair<ll,ll>> st;
    for(ll i=1;i<=50000;i++){
        ll square = i*i;
        if((square-x*x)>0 && (square-x*x)%(4*c*d)==0){
            ll ab = (square-x*x)/(4*c*d);
            if((i-x)>0 && (i-x)%(2*d)==0){
                ll gd = (i-x)/(2*d);
                if(gd>0 && ab%gd==0){
                    ll lc=ab/gd;
                    pair<ll,ll> p(gd,lc);
                    st.insert(p);
                }
                
            }
        }
    }
    for(auto it=st.begin();it!=st.end();it++){
        pair <ll,ll> p=*it;
        ans+=countPairs(p.F,p.S);
    }
    cout<<ans<<"\n";

}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
sieve();
TestCase{
    solve();
}
} 