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

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

/*void insert(Node* root,int val){
    while(root!=NULL){
        if(val<=root->data){
            if(root->left==NULL){
                Node* newNode=new Node(val);
                root->left=newNode;
                break;
            }
            else 
                root=root->left;
        }
        else{
            if(root->right==NULL){
                Node* newNode=new Node(val);
                root->right=newNode;
                break;
            }
            else{
                root=root->right;
            }
        }
    }
    
}
*/

Node* insert(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
    }
    else if(data<=root->data){
        root->left=insert(root->left,data);
    }
    else{
        root->right=insert(root->right,data);
    }
    return root;
}

void preOrder(Node* root){
    if(root==NULL)
        return;
    else{
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}



void solve(){
    Node* root=NULL;
    ll n;cout<<"Number of Nodes?:"<<"\n";cin>>n;
    vector<int> v;
    for(ll i=0;i<n;i++){int temp;cin>>temp;v.pb(temp);}
    for(int i=0;i<n;i++)
        root=insert(root,v[i]);
    
    preOrder(root);
    
    


}

int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
solve();
}