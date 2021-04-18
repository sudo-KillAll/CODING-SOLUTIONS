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
#include "bits/stdc++.h"
 
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



unsigned long long power(unsigned long long x,
								ll y, ll p)
{
	unsigned long long res = 1; // Initialize result

	x = x % p; // Update x if it is more than or
	// equal to p

	while (y > 0)
	{
	
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,
											long long p)
{
	return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
								long long r, long long p)
{
	// If n<r, then nCr should return 0
	if (n < r)
		return 0;
	// Base case
	if (r == 0)
		return 1;

	// Fill factorial array so that we
	// can find all factorial of r, n
	// and n-r
	unsigned long long fac[n + 1];
	fac[0] = 1;
	for (ll i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % p;

	return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;
}



ll facMod(ll n,ll p){
    if(n==1 || n==0)
        return 1;
    ll ans = 1;
    for(ll i=n;i>=1;i--){
        ans = (ans*i)%p;
    }
    return ans%p;
}









void solve(){
    ll mod = 1e9+7;
    ll n;cin>>n;
    vi v(n);
    for(auto &i:v)  cin>>i;
    vi cntZero(32,0),cntOne(32,0);
    for(auto i:v){
        string s = bin(i);
        for(ll j=0;j<32;j++){
            if(s[j]=='0')   cntZero[j]++;
            else    cntOne[j]++;
        }
    }
    map<ll,ll> mp;
    ll ans = 0;
    for(auto i:v)   mp[i]++;
    for(auto it=mp.begin();it!=mp.end();it++){
        ll value = it->F,cnt = it->S;
        if(cnt>=2){
            string s = bin(value);
            bool found = true;
            for(ll j=0;j<32;j++){
                if(s[j]=='1'){
                    if(cntOne[j]!=n){
                        found = false;
                        break;
                    }
                }
            }
            if(found){
                //cout<<"here\n";
                ans =(ans+(((nCrModPFermat(cnt,2,mod)*2)%mod)*(facMod(n-2,mod)))%mod)%mod;
            }
        }
    }
    cout<<ans<<"\n";

}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase
solve();
} 