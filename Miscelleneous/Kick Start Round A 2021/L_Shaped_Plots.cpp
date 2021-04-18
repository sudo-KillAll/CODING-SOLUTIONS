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

void solve(ll tst){

    ll n,m;cin>>n>>m;
    ll arr[n][m];
    ll ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    ll left[n][m];
    for(ll i=0;i<n;i++){
        left[i][0]=arr[i][0];
    }
    for(ll i=0;i<n;i++){
        for(ll j=1;j<m;j++){
            if(arr[i][j]==1){
                left[i][j]=left[i][j-1]+1;
            }
            else{
                left[i][j]=0;
            }
        }
    }


    ll right[n][m];
    for(ll i=0;i<n;i++){
        right[i][m-1]=arr[i][m-1];
    }

    for(ll i=0;i<n;i++){
        for(ll j=m-2;j>=0;j--){
            if(arr[i][j]==1){
                right[i][j]=right[i][j+1]+1;
            }
            else{
                right[i][j]=0;
            }
        }
    }

    ll top[n][m];
    for(ll j=0;j<m;j++){
        top[0][j]=arr[0][j];
    }
    for(ll i=1;i<n;i++){
        for(ll j=0;j<m;j++){
            if(arr[i][j]==1){
                top[i][j]=top[i-1][j]+1;
            }
            else{
                top[i][j]=0;
            }
        }
    }

    ll bottom[n][m];
    for(ll j=0;j<m;j++){
        bottom[n-1][j]=arr[n-1][j];
    }
    for(ll i=n-2;i>=0;i--){
        for(ll j=0;j<m;j++){
            if(arr[i][j]==1){
                bottom[i][j]=bottom[i+1][j]+1;
            }
            else{
                bottom[i][j]=0;
            }
        }
    }
    // for(ll i=0;i<n;i++){
    //     for(ll j=0;j<m;j++){
    //         cout<<top[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    ll zero = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            //cout<<"for"<<i<<" "<<j<<" "<<left[i][j]<<" "<<right[i][j]<<" "<<top[i][j]<<" "<<bottom[i][j]<<" ";
            ans+=max(min(left[i][j]/2,top[i][j])-1,zero);
            ans+=max(min(left[i][j],top[i][j]/2)-1,zero);
            ans+=max(min(right[i][j]/2,top[i][j])-1,zero);
            ans+=max(min(right[i][j],top[i][j]/2)-1,zero);
            ans+=max(min(left[i][j]/2,bottom[i][j])-1,zero);
            ans+=max(min(left[i][j],bottom[i][j]/2)-1,zero);
            ans+=max(min(right[i][j]/2,bottom[i][j])-1,zero);
            ans+=max(min(right[i][j],bottom[i][j]/2)-1,zero);
        }
        //cout<<endl;
    }
    cout<<"Case #"<<tst<<": "<<ans<<"\n";



}
 
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
ll tst;cin>>tst;
for(ll i=1;i<=tst;i++){
    solve(i);
}
} 