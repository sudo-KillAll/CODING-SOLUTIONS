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
//string ans="";
// ll lcs(string s,string t,ll i,ll j){
//     if(i>=s.length() || j>=t.length())
//         return 0;
//     else{
//         if(s[i]==t[j]){
//             //ans+=s[i];
//             return 1+lcs(s,t,i+1,j+1);   
//         }
//         else{
//             ll v1=lcs(s,t,i+1,j),v2=lcs(s,t,i,j+1);
//             return max(v1,v2);
//         }
//     }
// }


void solve(){
    string s,t;cin>>s>>t;
    //cout<<lcs(s,t,0,0);
    //cout<<ans;

    ll n=s.length(),m=t.length();

    ll lcs[n+1][m+1];
    FOR(i,0,n+1)
        FOR(j,0,m+1)
            lcs[i][j]=0;
    

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else{
                lcs[i][j]=max(lcs[i][j-1],lcs[i-1][j]);
            }
        }
    }
    //cout<<lcs[n][m];
    // FOR(i,0,n+1){
    //     FOR(j,0,m+1)
    //         cout<<lcs[i][j]<<" ";
    //     cout<<"\n";
    // }   
        
        
    string ans="";
    ll i=n,j=m;
    while(i>=1 && j>=1){
        if(s[i-1]==t[j-1]){
            ans+=s[i-1];
            i--;j--;
        }
        else if(lcs[i-1][j]>lcs[i][j-1])
            i--;
        else
            j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
        

}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
solve();
} 