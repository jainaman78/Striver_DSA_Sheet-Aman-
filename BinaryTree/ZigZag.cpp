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

vector<vector<int>> zigzagLevelOrder(Node* root){
      vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
        bool leftotright=true;
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int s=q.size();
            vector<int>temp(s);
            for(int i=0;i<s;i++){
                Node* front=q.front();
                q.pop();
                int index=leftotright?i:s-i-1;
                temp[index]=front->data;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            ans.push_back(temp);
            leftotright=!leftotright;
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