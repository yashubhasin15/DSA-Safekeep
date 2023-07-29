#include<iostream>
using namespace std;

class TrieNode{
	public:
	char data;
	TrieNode** children;
	bool isTerminal;

	TrieNode(char data){
		this->data= data;
		children= new TrieNode*[26];
		for(int i=0;i<26;i++){
			children[i]=NULL;
		}
		isTerminal= false;
	}
};

class Trie{
	TrieNode* root;

	public:
	Trie(){
		root= new TrieNode('\0');
	}

	void insertWord(string word){ //for user
		insertWord(root,word);
	}

	void insertWord(TrieNode* root, string word){
		if(word.length()==0){
			root->isTerminal= true;
			return;
		}

		int index= word[0]-'a'; //this will give index of the first character in word
		TrieNode* child;
		if(root->children[index]==NULL){
			child= new TrieNode(word[0]);
			root->children[index]= child;
		}
		else{
			child= root->children[index];
		}

		insertWord(child,word.substr(1));

	}

	bool searchWord(string word){ //for user
		return searchWord(root,word);
	}

	bool searchWord(TrieNode* root, string word){
		if(root==NULL){
			return false;
		}
		if(word.length()==0){
			return root->isTerminal;
		}
		int index= word[0]-'a';
		return searchWord(root->children[index], word.substr(1));
	}

	void removeWord(string word){
		removeWord(root,word);
	}

	void removeWord(TrieNode* root, string word){
		if(root==NULL){
			return;
		}
		if(word.length()==0){
			root->isTerminal= false;
			return;
		}
		int index= word[0]-'a';
		TrieNode* child= root->children[index];
		removeWord(child,word.substr(1));

		//now we need to dealocate the nodes. Condition is that node to be deleted should not be terminal node and have no children
		if(child->isTerminal==false){
			for(int i=0;i<26;i++){
				if(child->children[i]!=NULL){
					return; //if node has a child, it means its a part of another word, so we dont delete it
				}
			}
			delete child;
			root->children[index]=NULL;
		}
	}
};


int main(){
	Trie t;
	t.insertWord("hello");
	cout<<t.searchWord("hello")<<endl;
	t.removeWord("hello");
	cout<<t.searchWord("hello")<<endl;
	return 0;
}