#include<bits/stdc++.h>

#define ll long long int
#define vi vector<ll>
#define mi map<ll,ll>
#define test ll testcase;cin>>testcase;while(testcase--)

using namespace std;
ll spf[10000001];//Initialize smallest prime factor array

void initialize(){
    ll maxi=10000001;
    for(ll i=0;i<maxi;i++)
        spf[i]=-1;
    for(ll i=2;i*i<maxi;i++){
    if(spf[i]==-1){
        spf[i]=i;
        for(ll j=i*i;j<maxi;j+=i){
            if(spf[j]==-1)
                spf[j]=i;
        }
            
    }
}
}


void solve(){

    ll n;cin>>n;
    cout<<"prime factors of number n are: \n";
    //cout<<spf[3];
    while(true){
        if(n==1)
            break;
        else{
            cout<<spf[n]<<" ";
            n=n/spf[n];
        }
    }

}



using namespace std;
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
initialize();
solve();
}