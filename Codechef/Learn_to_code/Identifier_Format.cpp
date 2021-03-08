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

void solve(){
    char x;cin>>x;
    string a,b;cin>>a>>b;
    string ans="";
    switch (x)
    {
    case 'A':
        for(int i=0;i<a.length();i++)
            ans+=tolower(a[i]);
        ans+=toupper(b[0]);
        for(int i=1;i<b.size();i++)
            ans+=tolower(b[i]);
        break;
    case 'B':
        for(int i=0;i<a.length();i++)
            ans+=tolower(a[i]);
        ans+='_';
        for(int i=0;i<b.size();i++)
            ans+=tolower(b[i]);
        break;
    
    case 'C':
        for(int i=0;i<a.size();i++)
            ans+=toupper(a[i]);
        ans+='_';
        for(int i=0;i<b.size();i++)
            ans+=toupper(b[i]);
        break;
    case 'D':
        ans+=toupper(a[0]);
        for(int i=1;i<a.length();i++)
            ans+=tolower(a[i]);
        ans+='-';
        ans+=toupper(b[0]);
        for(int i=1;i<b.length();i++)
            ans+=tolower(b[i]);
        break;

    default:
        int cnt=0;
        for(int i=0;i<a.length();i++){
            if(cnt%2==0)
                ans+=tolower(a[i]);
            else
                ans+=toupper(a[i]);
            cnt++;
        }
        ans+='|';
        cnt=0;
        for(int i=0;i<b.length();i++){
            if(cnt%2==0)
                ans+=tolower(b[i]);
            else
                ans+=toupper(b[i]);
            cnt++;
        }
        break;
    }
    cout<<ans<<"\n";
    
}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase{
    solve();
}
} 