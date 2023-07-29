#include<iostream>
using namespace std;
#include<queue>
#include<climits>
#include<string>


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
class Quadruplet{
  public:
  int min;
  int max;
  int height;
  bool isBST;

  Quadruplet(){
    min=INT_MAX;
    max=INT_MIN;
    height=0;
    isBST=true;
  }
};

Quadruplet largestBST(BinaryTreeNode<int>* root){
  if(root==NULL){
    Quadruplet q;
    return q;
  }
  Quadruplet ans;
  Quadruplet left= largestBST(root->left);
  Quadruplet right= largestBST(root->right);

  ans.isBST= left.isBST && right.isBST && (root->data > left.max) && (root->data <= right.min);
  if(ans.isBST){
    ans.height= 1+max(left.height,right.height);
  }
  else{
    ans.height= max(left.height,right.height);
    return ans; //we are returning from here because if the lower subtree is not a bst, then ofcourse the upper tree cannot be a BST, so we need not calculate min and max
  }

  ans.min= min(root->data,min(left.min,right.min));
  ans.max= max(root->data,max(left.max,right.max));

  return ans;

}

// QUESTION 2
void replaceWithSumOfGreaterNodes(BinaryTreeNode<int>* root,int* sum){
  if(root==NULL){
    return;
  }

  replaceWithSumOfGreaterNodes(root->right,sum);

  int nodeData= root->data;
  root->data= *sum;
  *sum= *sum + nodeData;

  replaceWithSumOfGreaterNodes(root->left,sum);
}

// QUESTION 3 
void pathSumRootToLeaf(BinaryTreeNode<int>* root, int sum, string s=""){
  if(root==NULL){
    return;
  }
  if(root->left==NULL && root->right==NULL && root->data==sum){
    s += to_string(root->data);
    cout<<s<<endl;
    return;
  }

  pathSumRootToLeaf(root->left, sum - root->data, s+to_string(root->data)+"->");
  pathSumRootToLeaf(root->right, sum - root->data, s+to_string(root->data)+"->");
}

// QUESTION 4
void printAtDepthK(BinaryTreeNode<int>* root,int k){
  if(root==NULL){
    return;
  }
  if(k==0){
    cout<<root->data<<" ";
    return;
  }
  printAtDepthK(root->left,k-1);
  printAtDepthK(root->right,k-1);
}

int nodesAtDistanceKfromSpecificNode(BinaryTreeNode<int>* root,int dist, int data){
  if(root==NULL){
    return -1;
  }

  if(root->data==data){
    printAtDepthK(root,dist);
    return 1;
  }
  
  int leftDist= nodesAtDistanceKfromSpecificNode(root->left,dist,data);
  if(leftDist!=-1){
    if(leftDist==dist){
      cout<<root->data<<" ";
      return -1;
    }
    int remainDist= dist-leftDist-1;
    printAtDepthK(root->right,remainDist);
    return leftDist+1;
  }

  int rightDist= nodesAtDistanceKfromSpecificNode(root->right,dist,data);
  if(rightDist!=-1){
    if(rightDist==dist){
      cout<<root->data<<" ";
      return -1;
    }
    int remainDist= dist-rightDist-1;
    printAtDepthK(root->left,remainDist);
    return rightDist+1;
  }

  return -1;
}

// QUESTION 5
void convertBSTtoSortedVector(BinaryTreeNode<int>* root, vector<int> &v){
  if(root==NULL){
    return;
  }

  convertBSTtoSortedVector(root->left,v);
  v.push_back(root->data);
  convertBSTtoSortedVector(root->right,v);
}

void printPairSum(vector<int> v, int sum){
  int i= 0;
  int j= v.size()-1;

  while(i<j){
    if(v[i]+v[j]==sum){
      cout<<v[i]<<","<<v[j]<<endl;
      i++;
      j--;
    }
    else if(v[i]+v[j]<sum){
      i++;
    }
    else{
      j--;
    }
  }
}

int main(){
  BinaryTreeNode<int>* root= takeInputLevelWise();

  // Q1
  Quadruplet q= largestBST(root);
  cout<<"Height of largest BST in given binary tree is "<<q.height<<endl;

  // Q2
  // int sum=0;
  // replaceWithSumOfGreaterNodes(root,&sum); //this will change the root and will convert it into non BST, so carefull while using bst functions on root after this.
  // printBinaryTreeLevelWise(root);

  // Q3 (normal binary tree question)
  // test case for this-> 1 2 3 4 5 -1 6 -1 -1 8 -1 2 7 -1 -1 -1 4 -1 -1 -1 -1
  int sum=16;
  pathSumRootToLeaf(root,sum);

  // Q4 (normal binary tree question)
  // test case same as Q3
  int dist=2;
  int data=3;
  nodesAtDistanceKfromSpecificNode(root,dist,data);
  cout<<endl;

  // Q5
  vector<int> v;
  convertBSTtoSortedVector(root,v);
  int pairsum=10;
  printPairSum(v,pairsum);

}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1   this is bst
// 1 2 3 4 5 -1 7 -1 -1 6 -1 8 9 -1 -1 -1 -1 -1 -1 -1   this is not bst