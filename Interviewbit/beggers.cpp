/*
Problem:
    There are N (N > 0) beggars sitting in a row outside a temple. Each beggar initially has an empty pot. When the devotees come to the temple, they donate some amount of coins to these beggars. Each devotee gives a fixed amount of coin(according to his faith and ability) to some K beggars sitting next to each other.

Given the amount donated by each devotee to the beggars ranging from i to j index, where 1 <= i <= j <= N, find out the final amount of money in each beggar's pot at the end of the day, provided they don't fill their pots by any other means.

Approach:
    This question is based on range update query;
    1) Initialize a vector of size N with all zeros. let V
    2) for each devotee do;
        v[first]+=val;
        v[second]-=val(if second in range[1,n])
    3) iterate through vector from [1,n] and do;
        v[i]+=v[i-1];
    4) return the vector.
*/

#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define vi vector<ll>
#define mi map<ll,ll>
#define test ll testcase;cin>>testcase;while(testcase--)

using namespace std;

void solve(){
    ll A;cin>>A;
    vector<vector<ll>> B;
    ll no_of_devotee;cin>>no_of_devotee;
    for(ll i=0;i<no_of_devotee;i++){
        vi temp;
        for(int j=0;j<3;j++){ll val;cin>>val;temp.pb(val);}
        B.pb(temp);
    }

    vector<ll> v(A,0);
    for(ll k=0;k<B.size();k++){
        ll i=B[k][0]-1,j=B[k][1],val=B[k][2];
        v[i]+=val;
        if(j<A)
            v[j]-=val;
    }
    for(ll i=1;i<A;i++)
        v[i]+=v[i-1];
    
    for(ll i=0;i<A;i++)
        cout<<v[i]<<" ";

}



using namespace std;
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
solve();
}