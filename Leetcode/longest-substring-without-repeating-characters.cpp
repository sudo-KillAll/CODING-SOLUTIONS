#include<bits/stdc++.h>

#define ll long long int
#define vi vector<ll>
#define mi map<ll,ll>
#define test ll testcase;cin>>testcase;while(testcase--)

using namespace std;

int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        int ans=1,n=s.length();
        set<char> a;
        for(int i=0;i<n-1;i++){
            a.clear();
            for(int j=i;j<min(i+128,n);j++){
                int n1=a.size(),n2;
                a.insert(s[j]);
                n2=a.size();
                if(n1==n2){
                    break;
                    }
                
            }
            int m=a.size();
            ans=max(ans,m);
            
        }
        return ans;
    }



using namespace std;
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
string s;cin>>s;
cout<<lengthOfLongestSubstring(s);
}