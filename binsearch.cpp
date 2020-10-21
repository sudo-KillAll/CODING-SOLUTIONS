#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll pivsearch(ll arr[],ll l,ll h){
	if(l>h)
		return -1;

	ll  mid=(l+h)/2;
	//cout<<mid<<"  ";
	if(mid>l && arr[mid]<arr[mid-1])
		return mid-1;
	if(mid<h && arr[mid+1]<arr[mid])
		return mid;
	if(arr[l]>arr[mid])
		return pivsearch(arr,l,mid-1);
	else
		return pivsearch(arr,mid+1,h);
}
ll binsearch(ll arr[],ll l,ll h,ll ele){
	if(h<l)
		return -1;
	
	ll mid=(l+h)/2;
	if(arr[mid]==ele)
		return mid;
	else if(arr[mid]>ele)
		return binsearch(arr,l,mid-1,ele);
	else
		return binsearch(arr,mid+1,h,ele);
		
}

int main() {
	ll n;cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++) cin>>arr[i];
	ll piv=pivsearch(arr,0,n-1);
	cout<<piv;
	ll ele;cin>>ele;
	if(piv==-1)
		cout<<binsearch(arr,0,n-1,ele);
	else{
		if(arr[piv]==ele)
			cout<<piv;
		if(ele<arr[0])
			cout<<binsearch(arr,piv+1,n-1,ele);
		else
			cout<<binsearch(arr,0,piv,ele);
	}
	return 0;
}
