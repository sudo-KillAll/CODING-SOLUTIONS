/* 
Problem:
    Given an array of n innteger,
    We have to find the first positive integer which is not present in array.
    Eg . arr=[-1,3,2,0,4] ans =1;
         arr=[-1,0,1,2,3] ans=4;

Approach:
    If we observer carefully , we can see that the answer to the question 
    will lie in range [1,n+1].(Think about it)

    steps:
        1) traverse the array , if the array element is not in range [1,n] ignore it.
        2) if element is in range and arr[i]!=i+1 then do;
            swap arr[arr[i]-1] and arr[i] with condition that if arr[arr[i]-1]!=arr[i];
        3) Do this for all elements.
        4) Now traverse the array again and if arr[i]!=i+1 then this index+1 is answer,
            if we do not find any such index then the answer is n+1.
*/



#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define vi vector<ll>
#define mi map<ll,ll>
#define test ll testcase;cin>>testcase;while(testcase--)

using namespace std;

ll solve(){
    ll n;cin>>n;
    vi arr;
    for(ll i=0;i<n;i++){ll temp;cin>>temp;arr.pb(temp);}
    for(ll i=0;i<n;i++){
        if(arr[i]!=i+1){
            while(true){
                if(arr[i]<=0 || arr[i]>n || arr[i]==i+1) // base condition
                    break;
                else{
                	if(arr[arr[i]-1]==arr[i]) // To check if inifite loop Eg [2,2,2,2]
                		break;
                  swap(arr[arr[i]-1],arr[i]);
                }
                
            }
        }
    }
    for(ll i=0;i<n;i++)
    	cout<<arr[i]<<" ";
    
    for(ll i=0;i<n;i++)
        if(arr[i]!=i+1)
            return i+1;
    return n+1;
            


}



using namespace std;
int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
cout<<solve();
}