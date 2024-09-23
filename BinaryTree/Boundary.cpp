#include<bits/stdc++.h>
using namespace std;
vector<int>Ans;
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
            Ans.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
bool isLeaf(Node * root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
}
void leftboundary(Node*root,vector<int>&ans){
    Node* curr = root->left;
        while (curr) {
            
            if (!isLeaf(curr)) {
                ans.push_back(curr->data);
            }
           
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
}

void leaf(Node*root,vector<int>&ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left){
        leaf(root->left,ans);
    }
    if(root->right){
        leaf(root->right,ans);
    }
}

void rightboundary(Node* root,vector<int>&ans){
    Node* curr = root->right;
        vector<int> temp;
        while (curr) {
            // If the current node is not a leaf,
            // add its value to a temporary vector
            if (!isLeaf(curr)) {
                temp.push_back(curr->data);
            }
            // Move to the right child if it exists,
            // otherwise move to the left child
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        // Reverse and add the values from
        // the temporary vector to the result
        for (int i = temp.size() - 1; i >= 0; --i) {
            ans.push_back(temp[i]);
        }
}
vector<int>Boundary(Node*root){
    vector<int>ans;
    if(root==NULL){
        return {};
    }
    //left boundary
    ans.push_back(root->data);
    leftboundary(root,ans);
    leaf(root,ans);
    rightboundary(root,ans);

    return ans;
}

int main(){
    Node*temp;
    Node* root=create(temp);
    levelorder(root);
    vector<int>ans=Boundary(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
return 0;
}