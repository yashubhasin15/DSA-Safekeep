#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<climits>
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

bool searchInBST(BinaryTreeNode<int>* root, int x){
  if(root==NULL){
    return false;
  }
  if(root->data==x){
    return true;
  }
  else if(root->data>x){
    return searchInBST(root->left,x);
  }
  else{
    return searchInBST(root->right,x);
  }
}

void printElementsInRange(BinaryTreeNode<int>* root, int min, int max){
  if(root==NULL){
    return;
  }
  if(root->data>max){
    printElementsInRange(root->left,min,max);
  }
  else if(root->data<min){
    printElementsInRange(root->right,min,max);
  }
  else{
    cout<<root->data<<" ";
    printElementsInRange(root->left,min,max);
    printElementsInRange(root->right,min,max);
  }
}

class Triplet{
  public:
  int minRight;
  int maxLeft;
  bool isBST;

  Triplet(){
    minRight=INT_MAX;
    maxLeft=INT_MIN;
    isBST=true;
  }
};

Triplet checkBST(BinaryTreeNode<int>* root){
  if(root==NULL){
    Triplet t;
    return t;
  }
  Triplet ans;
  Triplet left= checkBST(root->left);
  Triplet right= checkBST(root->right);

  ans.isBST= left.isBST && right.isBST && (root->data > left.maxLeft) && (root->data <= right.minRight);
  if(ans.isBST==false) return ans;

  ans.maxLeft= max(root->data,max(left.maxLeft,right.maxLeft));
  ans.minRight= min(root->data,min(left.minRight,right.minRight));
  
  return ans;
}

bool checkBST2(BinaryTreeNode<int>* root, int min=INT_MIN, int max=INT_MAX){
  if(root==NULL){
    return true;
  }
  if(root->data < min || root->data > max){
    return false;
  }

  bool checkLeft= checkBST2(root->left,min,root->data-1);
  bool checkRight= checkBST2(root->right,root->data,max);
  return checkLeft && checkRight;

}

BinaryTreeNode<int>* makeBSTfromSortedArray(int arr[],int start, int end){
  if(start>end){
    return NULL;
  }
  int mid= (start+end)/2;
  BinaryTreeNode<int>* root= new BinaryTreeNode<int>(arr[mid]);
  root->left= makeBSTfromSortedArray(arr,start,mid-1);
  root->right= makeBSTfromSortedArray(arr,mid+1,end);
  return root;
}

class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data= data;
    this->next= NULL;
  }
};

Node* sortedLLfromBST(BinaryTreeNode<int>* root){
  if(root==NULL){
    return NULL;
  }

  Node* head=NULL;
  Node* left= sortedLLfromBST(root->left);
  Node* newNode= new Node(root->data);
  if(left!=NULL){
    Node* temp=left;
    while(temp->next!=NULL){
      temp=temp->next;
    }
    temp->next=newNode;
    head= left;
  }
  else{
    head= newNode;
  }
  Node* right= sortedLLfromBST(root->right);
  newNode->next= right;
  return head;
}

Node* currHead=NULL;

void sortedLLfromBST2(BinaryTreeNode<int>* root){
  if(root->right!=NULL){
    sortedLLfromBST2(root->right);
  }
  Node* newNode= new Node(root->data);
  newNode->next=currHead;
  currHead= newNode;
  if(root->left!=NULL){
    sortedLLfromBST2(root->left);
  }
}

int main(){
  BinaryTreeNode<int>* root= takeInputLevelWise();
  printBinaryTreeLevelWise(root);

  cout<<(searchInBST(root,5)?"found":"not found")<<endl;

  printElementsInRange(root,3,6);
  cout<<endl;

  cout<<checkBST(root).isBST<<endl;
  cout<<checkBST2(root)<<endl;

  int arr[]={1,2,3,4,5,6,7,8};
  BinaryTreeNode<int>* bst=makeBSTfromSortedArray(arr,0,7);
  printBinaryTreeLevelWise(bst);

  Node* head= sortedLLfromBST(root);
  while(head!=NULL){
    cout<<head->data<<"->";
    head= head->next;
  };
  cout<<endl;
  
  sortedLLfromBST2(root);
  while(currHead!=NULL){
    cout<<currHead->data<<"->";
    currHead= currHead->next;
  };

  delete root;
  return 0;
}

// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1   this is bst
// 1 2 3 4 5 8 -1 -1 9 6 7 -1 -1 -1 -1 -1 -1 -1 -1   this is not bst