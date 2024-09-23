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

vector<vector<int>> verticalTraversal(Node* root) {
        vector<vector<int>> ans;
      queue<pair<Node*,pair<int,int>>> q;
      map<int,map<int,multiset<int>>> m;
      if(root == NULL)
        return ans;
      q.push({root,{0,0}});
      while(!q.empty())
      {
          auto it = q.front();
          q.pop();
          Node* t = it.first;
          int v = it.second.first;
          int l = it.second.second;
          m[v][l].insert(t->data);
          if(t->left)
            q.push({t->left,{v-1,l+1}});
        if(t->right)
            q.push({t->right,{v+1,l+1}});
      }  

      for(auto it : m)
      {
          vector<int> temp;
          for(auto i : it.second)
          {
              for(auto j: i.second)
              {
                  temp.push_back(j);
              }
          }
          ans.push_back(temp);
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