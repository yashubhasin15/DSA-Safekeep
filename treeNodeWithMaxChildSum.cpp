#include<iostream>
using namespace std;
#include<vector>
#include<queue>

template <typename T>
class TreeNode{
  public:
  T data;
  vector<TreeNode<T>*> children;

  TreeNode(T data){
    this->data= data;
  }
};

TreeNode<int>* takeInputLevelWise(){
  int rootData;
  cout<<"Enter data of root node"<<endl;
  cin>>rootData;
  TreeNode<int>* root= new TreeNode<int>(rootData);
  queue<TreeNode<int>*> pendingNodes;
  pendingNodes.push(root);

  while(pendingNodes.size() != 0){
    TreeNode<int>* front= pendingNodes.front();
    pendingNodes.pop();

    int n;
    cout<<"Enter number of children of "<<front->data<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
      int childData;
      cout<<"Enter data of "<<i<<"th node of "<<front->data<<endl;
      cin>>childData;
      TreeNode<int>* child= new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;

}

class Pair{
  public:
  int sum;
  TreeNode<int>* root;

  Pair(TreeNode<int>* root){
    this->root= root;
    this->sum= root->data;
  }
};

Pair* maxChildSum(TreeNode<int>* root){
  Pair* ans= new Pair(root);
  for(int i=0;i<root->children.size();i++){
    ans->sum += root->children[i]->data;
  }
  for(int i=0;i<root->children.size();i++){
    Pair* child=maxChildSum(root->children[i]);
    if(child->sum > ans->sum){
      ans= child;
    }
  }
  return ans;
}

int main(){
  TreeNode<int> *root= takeInputLevelWise();
  cout<<maxChildSum(root)->root->data;
  return 0;
}