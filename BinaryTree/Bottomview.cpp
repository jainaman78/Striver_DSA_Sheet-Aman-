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
vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int>topnode;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node* frontnode=temp.first;
            int hd=temp.second;
                topnode[hd]=frontnode->data;
            if(frontnode->left){
                q.push(make_pair(frontnode->left,hd-1));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,hd+1));
            }
        }
        for(auto i:topnode){
            ans.push_back(i.second);
        }
        return ans;
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