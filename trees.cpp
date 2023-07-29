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

  ~TreeNode(){//we will use postorder traversal to delete child nodes first and then delete parent node recursively
    for(int i=0;i<this->children.size();i++){
      delete this->children[i]; //this will call destructor of child nodes which inturn will call their child's destructor until we reach leaf node.
    }
    //for the leaf node, as there are no children, we wont enter loop and destructor will itself delete that leaf node before returning.
    //hence recursively all the nodes of the tree will be deleted.
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

TreeNode<int>* takeInput(){
  int data;
  cout<<"Enter data"<<endl;
  cin>>data;
  TreeNode<int>* root= new TreeNode<int>(data);

  int n;
  cout<<"Enter number of nodes in "<<data<<endl;
  cin>>n;
  for(int i=0;i<n;i++){
    TreeNode<int>* child= takeInput();
    root->children.push_back(child);
  }
  return root;
}

void printTree(TreeNode<int>* root){
  if(root==NULL){
    return;
  }//this is not base case, its just incase an empty tree is passed in the function. The loop below itself will act as base case
  cout<<root->data<<":";
  for(int i=0;i<root->children.size();i++){
    cout<<root->children[i]->data<<",";
  }
  cout<<endl;
  for(int i=0;i<root->children.size();i++){
    printTree(root->children[i]);
  }
}

void printTreeLevelWise(TreeNode<int>* root){
  if(root==NULL){
    return;
  }
  queue<TreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(pendingNodes.size()!=0){
    TreeNode<int>* front= pendingNodes.front();
    pendingNodes.pop();
    cout<<front->data<<":";
    for(int i=0;i<front->children.size();i++){
      cout<<front->children[i]->data<<",";
      pendingNodes.push(front->children[i]);
    }
    cout<<endl;
  }
}

int countNodes(TreeNode<int>* root){
  if(root==NULL){//edge case
    return 0;
  }
  int ans=1;
  for(int i=0;i<root->children.size();i++){
    ans+=countNodes(root->children[i]);
  }
  return ans;
}

int treeHeight(TreeNode<int>* root){
  if(root==NULL){//edge case
    return 0;
  }
  int ans=0;
  for(int i=0;i<root->children.size();i++){
    int nodeHeight= treeHeight(root->children[i]);
    if(ans<nodeHeight){
      ans=nodeHeight;
    }
  }
  return 1+ans;
}

void printAtDepthK(TreeNode<int>* root, int k){
  if(root==NULL){//edge case
    return;
  }
  if(k==0){//base case
    cout<<root->data<<",";
    return;
  }
  for(int i=0;i<root->children.size();i++){
    printAtDepthK(root->children[i],k-1);
  }
}

int countLeafNodes(TreeNode<int>* root){
  int ans=0;
  if(root->children.size()==0){
    return 1;
  }
  for(int i=0;i<root->children.size();i++){
    ans+=countLeafNodes(root->children[i]);
  }
  return ans;
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

TreeNode<int>* nextLarger(TreeNode<int>* root, int x){
  if(root==NULL){
    return NULL;
  }
  TreeNode<int>* ans=NULL; 
  if(root->data > x){
    ans= root;
  }

  for(int i=0;i<root->children.size();i++){
    TreeNode<int>* temp= nextLarger(root->children[i],x);
    if(ans==NULL){
      ans=temp;
    }
    else if(temp!=NULL && temp->data<ans->data){
      ans= temp;
    }
  }
  return ans;
}

pair<TreeNode<int>*,TreeNode<int>*> secondLargestElement(TreeNode<int>* root){
  pair<TreeNode<int>*,TreeNode<int>*> ans(NULL,NULL);
  if(root==NULL){
    return ans;
  }
  ans.first = root;

  for(int i=0;i<root->children.size();i++){
    pair<TreeNode<int>*,TreeNode<int>*> child= secondLargestElement(root->children[i]);

    if(child.first->data > ans.first->data){
      if(child.second && child.second->data > ans.first->data){
        ans.first=child.first;
        ans.second=child.second;
      }
      else{
        ans.second= ans.first;
        ans.first=child.first;
      }
    }
    else if(ans.first!=child.first && (ans.second==NULL || child.first->data > ans.second->data)){
      ans.second=child.first;
    }
  }
  return ans;

}

void replaceWithDepth(TreeNode<int>* root,int depth=0){
  if(root==NULL){
    return;
  }
  root->data=depth;
  for(int i=0;i<root->children.size();i++){
    replaceWithDepth(root->children[i],depth+1);
  }
}

int main(){
  TreeNode<int> *root= takeInputLevelWise();
  printTreeLevelWise(root);
  cout<<"No of nodes= "<<countNodes(root)<<endl;
  cout<<"Height of tree= "<<treeHeight(root)<<endl;
  cout<<"No of leaf nodes= "<<countLeafNodes(root)<<endl;

  int k;
  cout<<"Enter depth: "<<endl;
  cin>>k;
  cout<<"Elements at depth "<<k<<" are ";
  printAtDepthK(root,k);
  cout<<endl;

  Pair* p= maxChildSum(root);
  cout<<"Node with max child sum is "<<p->root->data<<" and max sum is "<<p->sum<<endl;

  cout<<"Next larger node after 13 is "<<nextLarger(root,13)<<endl;
  
  cout<<"Second largest element in the tree is "<<secondLargestElement(root).second->data<<endl;

  replaceWithDepth(root);
  printTreeLevelWise(root);
  
  delete root; //this will call destructor of TreeNode class for root object.
  return 0;
}
