#include<bits/stdc++.h>

#define ll long long int
#define vi vector<ll>
#define mi map<ll,ll>
#define test ll testcase;cin>>testcase;while(testcase--)

using namespace std;

 bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){if(st.empty() || st.top()!='(') return false;st.pop();}
            else if(s[i]=='}'){if(st.empty() || st.top()!='{') return false;st.pop();}
            else if(s[i]==']'){if(st.empty() || st.top()!='[') return false;st.pop();}
            else st.push(s[i]);
        }
        if(!st.empty()) return false;
        return true;
    }



using namespace std;
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
string s;cin>>s;
  cout<<isValid(s);
}