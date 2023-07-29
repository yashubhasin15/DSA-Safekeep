#include<iostream>
using namespace std;

template<typename V>
class MapNode{
  public:
  string key;
  V value;
  MapNode<V>* next;

  MapNode(string key, V value){
    this->key= key;
    this->value= value;
    next= NULL;
  }

  ~MapNode(){
    delete next;
  }
};

template<typename V>
class Hashmap{
  int count;
  int bucketSize;
  MapNode<V>** bucket; //array of pointers to the MapNode
  
  public:

  Hashmap(){
    count=0;//this is the total elements in the map
    bucketSize=5;//this is the size of the map array, can be any value of ur choice
    bucket= new MapNode<V>*[bucketSize];
    for(int i=0;i<bucketSize;i++){
      bucket[i]=NULL;
    }
  }

  ~Hashmap(){
    for(int i=0;i<bucketSize;i++){
      delete bucket[i];
    }
    delete [] bucket;
  }

  private:
  int getBucketIndex(string key){
    int bucketIndex=0;
    int currCoff= 1;

    for(int i=key.size()-1; i>=0; i--){
      bucketIndex += key[i]*currCoff;
      bucketIndex= bucketIndex%bucketSize; //so that bucketIndex doesnt get bigger than INT_MAX for longer strings
      currCoff*=37; //37 is just a random value
      currCoff= currCoff%bucketSize; //so that currCoff doesnt get bigger than INT_MAX for longer strings
    }

    return bucketIndex%bucketSize;//to return index varying from 0 to bucketSize-1
  }

  void rehash(){
    MapNode<V>** temp= bucket;
    bucket= new MapNode<V>*[2*bucketSize];
    for(int i=0;i<2*bucketSize;i++){
      bucket[i]=NULL; //emptying the new array
    }
    int oldBucketSize= bucketSize;
    bucketSize*=2;
    count=0;

    //now we need to copy the elements into the new array but since now bucketSize is changed, we need to do hashing again. We cant just copy head of the 5 buckets into the new bucket array as now hash function will do %10 instead of %5
    for(int i=0;i<oldBucketSize;i++){
      MapNode<V>* head= temp[i];
      while(head!=NULL){
        string key= head->key;
        V value= head->value;
        insert(key,value); //this will do hasing and add elements into the new bucket array
        head= head->next;
      }
    }

    for(int i=0;i<oldBucketSize;i++){//deleting the old bucket array
      MapNode<V>* head= temp[i];
      delete head; //since we have used recursion in the MapNode destructor, the whole linked list will be deleted
    }
    delete [] temp;
  }

  public:
  int size(){
    return count;
  }

  void insert(string key, V value){
    int bucketIndex= getBucketIndex(key); //fetching the index at which we need to insert

    MapNode<V>* head= bucket[bucketIndex];
    while(head!=NULL){ //incase key is already present, we need to update the value
      if(head->key == key){
        head->value= value; 
        return;
      }
      head=head->next;
    }

    head= bucket[bucketIndex];
    MapNode<V>* node= new MapNode<V>(key,value);
    node->next=head;
    bucket[bucketIndex]= node;
    count++;

    double loadfactor= (1.0*count)/bucketSize; //load factor is the load(or entries) on each bucket.
    if(loadfactor>0.7){ //load factor should be less than 0.7 hypothetically to run the hashmap in O(1)
      rehash(); //rehashing will increase the number of buckets, so load factor will decrease
    }
  }

  V search(string key){
    int bucketIndex= getBucketIndex(key);
    MapNode<V>* head= bucket[bucketIndex];
    while(head!=NULL){
      if(head->key==key){
        return head->value;
      }
      head= head->next;
    }
    return 0;
  }

  V remove(string key){
    int bucketIndex= getBucketIndex(key);
    MapNode<V>* head= bucket[bucketIndex];
    MapNode<V>* prev= NULL;
    while(head!=NULL){
      if(head->key==key){
        if(prev==NULL){
          bucket[bucketIndex]=head->next;
        }
        else{
          prev->next= head->next;
        }
        V value= head->value;
        head->next=NULL;//so that when we call delete head, all the nodes after head are not deleted
        delete head;
        count--;
        return value;
      }
      prev= head;
      head=head->next;
    }
    return 0;
  }
};

int main(){
  Hashmap<int> h;
  h.insert("lund",1);
  h.insert("chus",2);
  h.insert("le",3);

  cout<<h.size()<<endl;
  cout<<h.search("loda")<<endl;
  cout<<h.search("chus")<<endl;
  cout<<h.remove("le")<<endl;
  cout<<h.remove("le")<<endl;
  cout<<h.size()<<endl;
  
  return 0;
}