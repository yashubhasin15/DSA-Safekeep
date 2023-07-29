#include<iostream>
#include<queue>
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

void printBinaryTree(BinaryTreeNode<int>* root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<":";
  if(root->left!=NULL){
    cout<<"L"<<root->left->data;
  }
   if(root->right!=NULL){
    cout<<"R"<<root->right->data;
  }
  cout<<endl;
  printBinaryTree(root->left);
  printBinaryTree(root->right);
}

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

BinaryTreeNode<int>* takeInput(){
  int data;
  cout<<"Enter data:"<<endl;
  cin>>data;
  if(data==-1){
    return NULL;
  }
  BinaryTreeNode<int>* root= new BinaryTreeNode<int>(data);
  BinaryTreeNode<int>* leftChild= takeInput();
  BinaryTreeNode<int>* rightChild= takeInput();
  root->left= leftChild;
  root->right= rightChild;
  return root;
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

int countNodes(BinaryTreeNode<int>* root){
  if(root==NULL){
    return 0;
  }
  int count=1;
  count+=countNodes(root->left);
  count+=countNodes(root->right);
  return count;
}

void inorder(BinaryTreeNode<int>* root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

class Pair{
  public:
  int height;
  int diameter;
};

// int height(BinaryTreeNode<int>* root){
//   if(root==NULL){
//     return 0;
//   }
//   int heightLeft= height(root->left);
//   int heightRight= height(root->right);
//   return 1+max(heightLeft,heightRight);
// }

// int diameter(BinaryTreeNode<int>* root){
//   if(root==NULL){
//     return 0;
//   }
//   int option1= height(root->left)+height(root->right);
//   int option2= diameter(root->left);
//   int option3= diameter(root->right);
//   return max(option1, max(option2,option3));
// }

Pair diameterHeight(BinaryTreeNode<int>* root){
  if(root==NULL){
    Pair p;
    p.height=0;
    p.diameter=0;
    return p;
  }
  Pair leftAns=diameterHeight(root->left);
  Pair rightAns=diameterHeight(root->right);
  
  int height= 1+max(leftAns.height,rightAns.height);
  int diameter= max(leftAns.height+rightAns.height,max(leftAns.diameter,rightAns.diameter));

  Pair p;
  p.height= height;
  p.diameter= diameter;
  return p;
}

int main(){
  BinaryTreeNode<int>* root= takeInputLevelWise();
  printBinaryTreeLevelWise(root);
  cout<<"Number of nodes: "<<countNodes(root)<<endl;
  cout<<"Height: "<<diameterHeight(root).height<<endl;
  cout<<"Diameter: "<<diameterHeight(root).diameter<<endl;
  inorder(root);
  delete root;
  return 0;
}

// 1 2 3 4 5 8 -1 -1 9 6 7 -1 -1 -1 -1 -1 -1 -1 -1
