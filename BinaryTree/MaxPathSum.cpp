#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int dt){
        this->data=dt;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* create(Node* root){
    int dt;
    cout<<"enter root data: ";
    cin>>dt;
    root=new Node(dt);
    if(dt==-1){
        return NULL;
    }
    cout<<"enter root's left: ";
    root->left=create(root->left);
    cout<<"enter root's right: ";
    root->right=create(root->right);
    return root;
}

void levelorder(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int solve(Node*root,int m){
    if(root==NULL){
        return 0;
    }
    int left=max(0,solve(root->left,m));
    int right=max(0,solve(root->right,m));

    m=max(m,left+right+root->data);
    return max(left,right)+root->data;
}

int maxPath(Node* root){
    int m=INT_MIN;
    return solve(root,m);
}
int main(){
    Node*temp;
    Node* root=create(temp);
    levelorder(root);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
return 0;
}