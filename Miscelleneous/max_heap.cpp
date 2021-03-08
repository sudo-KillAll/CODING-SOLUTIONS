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

void heapify(ll i,ll n,vi &heap){
    if(i>(n-1)/2)
        return;
    ll max=i;
    if(2*i+1<n && heap[2*i+1]>heap[max])
        max=2*i+1;
    if(2*i+2<n && heap[2*i+2]>heap[max])
        max=2*i+2;
    if(max!=i){
        swap(heap[max],heap[i]);
        heapify(max,n,heap);
    }
}

void formHeap(ll n,vi &heap){
    for(ll i=(n-1)/2;i>=0;--i){
        print(heap);
        cout<<"\n";
        heapify(i,n,heap);
    }
        
}

void solve(){
    ll n;cin>>n;
    vi heap;
    forn(n){ll temp;cin>>temp;heap.pb(temp);}
    cout<<"Step By step process of heapify:\n";
    formHeap(n,heap);
    
    //print(heap);
    cout<<"\n";
    if(is_heap(heap.begin(),heap.end()))
        cout<<"Formed successfully!:)";
    else
        cout<<"Work Hard;)";

}

int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
solve();
}