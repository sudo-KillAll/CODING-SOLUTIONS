#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define f first
#define s second
#define vi vector<ll>
#define mi map<ll,ll>
#define forn(n) for(ll i=0;i<n;i++)
#define mi map<ll,ll>
#define print(v) for(ll printing=0;printing<v.size();printing++){cout<<v[printing]<<' ';}
#define TestCase ll testcase;cin>>testcase;while(testcase--)
#define bin(n) bitset<32>(n).to_string();
using namespace std;

int lengthOfLIS(vi& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            auto it=lower_bound(ans.begin(),ans.end(),nums[i]);
            int ind=it-ans.begin();
            if(ind>=ans.size())
                ans.push_back(nums[i]);
            else
                ans[ind]=nums[i];
        }
        return ans.size();
    }


void solve(){
    ll n;cin>>n;
    vi nums;
    forn(n){ll temp;cin>>temp;nums.pb(temp);}
    cout<<lengthOfLIS(nums);
}

int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
TestCase
    solve();
}