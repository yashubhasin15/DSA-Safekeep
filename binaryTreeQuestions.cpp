#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

template <typename T>
class BinaryTreeNode{
  public:
  T data;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(T data){
    this->data= data;
    left= NULL;
    right= NULL;
  }

  ~BinaryTreeNode(){
    delete left;
    delete right;
  }
};

void printBinaryTreeLevelWise(BinaryTreeNode<int>* root){
  if(root==NULL){
    return;
  }
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);

  while(pendingNodes.size()!=0){
    BinaryTreeNode<int>* front= pendingNodes.front();
    pendingNodes.pop();

    cout<<front->data<<":";
    if(front->left!=NULL){
      cout<<"L"<<front->left->data;
      pendingNodes.push(front->left);
    }
    if(front->right!=NULL){
      cout<<"R"<<front->right->data;
      pendingNodes.push(front->right);
    }
    cout<<endl;
  }
}

BinaryTreeNode<int>* takeInputLevelWise(){
  int data,leftData,rightData;
  cout<<"Enter data of root"<<endl;
  cin>>data;
  if(data==-1){
    return NULL;
  }
  BinaryTreeNode<int>* root= new BinaryTreeNode<int>(data);
  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(pendingNodes.size()!=0){
    BinaryTreeNode<int>* front= pendingNodes.front();
    pendingNodes.pop();

    cout<<"Enter left data of "<<front->data<<endl;
    cin>>leftData;
    if(leftData!=-1){
      BinaryTreeNode<int>* leftChild= new BinaryTreeNode<int>(leftData);
      front->left= leftChild;
      pendingNodes.push(leftChild);
    }
   
    cout<<"Enter right data of "<<front->data<<endl;
    cin>>rightData;
    if(rightData!=-1){
      BinaryTreeNode<int>* rightChild= new BinaryTreeNode<int>(rightData);
      front->right= rightChild;
      pendingNodes.push(rightChild);
    }
    
  }
  return root;
}

// QUESTION 1
pair<bool,int> checkBalanced(BinaryTreeNode<int>* root){
  if(root==NULL){
    pair<bool,int> p;
    p.first=true;
    p.second=0;
    return p;
  }
  pair<bool,int> leftAns= checkBalanced(root->left);
  pair<bool,int> rightAns= checkBalanced(root->right);
  pair<bool,int> ans;
  if(leftAns.first && rightAns.first && abs(leftAns.second-rightAns.second)<=1){
    ans.first=true;
    ans.second=1+max(leftAns.second,rightAns.second);
  }
  else{
    ans.first=false;
  }
  return ans;
}

// QUESTION 2
void levelOrderTraversal(BinaryTreeNode<int>* root){
  if(root==NULL){
    return;
  }
  queue<BinaryTreeNode<int>*> q;
  q.push(root);
  q.push(NULL);

  while(q.size()!=0){
    BinaryTreeNode<int>* front= q.front();
    q.pop();
    if(front==NULL){
      cout<<endl;
      if(q.empty()){//this will stop the function from going into infinite loop after all nodes have been printed
        break;
      }
      q.push(NULL);
    }
    else{
      cout<<front->data<<" ";
      if(front->left!=NULL) q.push(front->left);
      if(front->right!=NULL) q.push(front->right);
    }
  }
}

// QUESTION 3
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int>* root){
  if(root==NULL){
    return root;
  }
  if(root->left==NULL && root->right==NULL){//base case
    delete root;
    root=NULL;
    return root;
  }
  root->left=removeLeafNodes(root->left);
  root->right=removeLeafNodes(root->right);
  return root;
}

// QUESTION 4
class LLNode{
  public:
  int data;
  LLNode* next;

  LLNode(int data){
    this->data= data;
    this->next= NULL;
  }
};

vector<LLNode*> LevelWiseLL(BinaryTreeNode<int>* root){
  queue<BinaryTreeNode<int>*> q;
  vector<LLNode*> v;
  if(root==NULL){
    return v;
  }
  LLNode* head=NULL;
  LLNode* tail=NULL;
  q.push(root);
  q.push(NULL);

  while(q.size()!=0){
    BinaryTreeNode<int>* front= q.front();
    q.pop();
    if(front==NULL){
      v.push_back(head);
      head=NULL;
      tail=NULL;
      if(q.empty()){
        break;
      }
      q.push(NULL);
      
    }
    else{
      if(front->left!=NULL) q.push(front->left);
      if(front->right!=NULL) q.push(front->right);

      if(head==NULL){
        head= new LLNode(front->data);
        tail=head;
      }
      else{
        LLNode* node= new LLNode(front->data);
        tail->next= node;
        tail=node;
      }
    }
  }
  return v;
}

// QUESTION 5
void ZigZagTree(BinaryTreeNode<int>* root){
  if(root==NULL){
    return;
  }
  stack<BinaryTreeNode<int>*> currStack;
  stack<BinaryTreeNode<int>*> nextStack;
  bool leftToRight=true;
  currStack.push(root);

  while(currStack.size()!=0){
    BinaryTreeNode<int>* top= currStack.top();
    currStack.pop();

    cout<<top->data<<" ";
    if(leftToRight){
      if(top->left!=NULL) nextStack.push(top->left);
      if(top->right!=NULL) nextStack.push(top->right);
    }
    else{
      if(top->right!=NULL) nextStack.push(top->right);
      if(top->left!=NULL) nextStack.push(top->left);
    }
    

    if(currStack.empty()){
      cout<<endl;
      leftToRight= !leftToRight;
      swap(currStack,nextStack);
    }
  }
}

// QUESTION 6
void duplicateNodeLeft(BinaryTreeNode<int>* root){
  if(root==NULL){
    return;
  }
  duplicateNodeLeft(root->left);
  duplicateNodeLeft(root->right);
  BinaryTreeNode<int>* oldLeft= root->left;
  root->left= new BinaryTreeNode<int>(root->data);
  root->left->left= oldLeft;
}

// QUESTION 7
vector<int> rootToNodePath(BinaryTreeNode<int>* root, int x){
  vector<int> v;
  if(root==NULL){
    return v;
  }
  if(root->data == x){
    v.push_back(root->data);
    return v;
  }
  vector<int> left= rootToNodePath(root->left,x);
  if(!left.empty()){
    left.push_back(root->data);
    return left;
  }
  vector<int> right= rootToNodePath(root->right,x);
  if(!right.empty()){
    right.push_back(root->data);
    return right;
  }

  return v;
}

// QUESTION 8
BinaryTreeNode<int>* findLCA(BinaryTreeNode<int>* root,int n1,int n2){
  if(root==NULL){
    return NULL;
  }
  if(root->data==n1 || root->data==n2){
    return root;
  }
  BinaryTreeNode<int>* left= findLCA(root->left,n1,n2);
  BinaryTreeNode<int>* right= findLCA(root->right,n1,n2);
  
  if(left && right){
    return root;
  }
  if(left){
    return left;
  }
  if(right){
    return right;
  }
  
  return NULL;
}

int main(){
  BinaryTreeNode<int>* root= takeInputLevelWise();
  printBinaryTreeLevelWise(root);
  cout<<"Balanced: "<<(checkBalanced(root).first?"Yes":"No")<<endl; // Q1
  root=removeLeafNodes(root); // Q2
  levelOrderTraversal(root); //Q3
  vector<LLNode*> v= LevelWiseLL(root); // Q4
  for(int i=0;i<v.size();i++){
    while(v[i]!=NULL){
      cout<<v[i]->data<<"->";
      v[i]=v[i]->next;
    }
    cout<<endl;
  }

  ZigZagTree(root); // Q5
  duplicateNodeLeft(root); // Q6
  printBinaryTreeLevelWise(root);

  vector<int> vc= rootToNodePath(root,5); // Q7
  for(int i=0;i<vc.size();i++){
    cout<<vc[i]<<" > ";
  }
  cout<<endl;

  BinaryTreeNode<int>* lca= findLCA(root,8,5); // Q8
  if(lca!=NULL) cout<<lca->data<<endl;


  delete root;
  return 0;
}

// 1 2 3 4 5 8 -1 -1 9 6 7 -1 0 -1 -1 -1 -1 -1 -1 -1 -1
