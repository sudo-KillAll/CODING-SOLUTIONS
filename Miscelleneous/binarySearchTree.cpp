#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode=new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root,int data){
    if(root == NULL)
        root = createNode(data);
    else if(data<=root->data)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right,data);
    return root;
}

bool search(Node* root,int data){
    if(root == NULL)
        return false;
    if(root->data == data)
        return true;
    else if(data <= root->data)
        return search(root->left,data);
    else
        return search(root->right,data);
}

int findMin(Node* root){
    if(root->left==NULL)
        return root->data;
    else
        return findMin(root->left);
}
int findMax(Node* root){
    if(root->right==NULL)
        return root->data;
    else
        return findMax(root->right);
}


int height(Node* root){
    if(root==NULL)
        return -1;
    else{
        int l=height(root->left);
        int r=height(root->right);
        int h=max(l,r)+1;
        //h=max(height(Node* root->left),height(Node* root->right))+1;
        return h;
    }
}

int main(){
    cout<<"Enter No of Nodes in binary tree: ";
    int n;cin>>n;
    Node* root=NULL;
    cout<<"Enter value of each nodes respectively:"<<"\n";
    while(n--){int x;cin>>x;root=insert(root,x);}
    cout<<"Enter no of queries: ";
    int q;cin>>q;
    while(q--){
        cout<<"Enter a value: ";
        int y;cin>>y;
        search(root,y)==true ? cout<<"Found"<<"\n":cout<<"Not Found"<<"\n";
    }
    cout<<findMin(root)<<" "<<findMax(root)<<" ";
    cout<<height(root);

}