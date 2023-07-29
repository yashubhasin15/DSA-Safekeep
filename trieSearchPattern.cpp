#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class TrieNode{
	public:
	char data;
	TrieNode** children;
	bool isTerminal;

	TrieNode(char data){
		this->data= data;
		children= new TrieNode*[256];
		for(int i=0;i<256;i++){
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

		int index= word[0]; //this will give index of the first character in word
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

	bool searchPattern(string word){
		return searchPattern(root,word);
	}

	bool searchPattern(TrieNode* root, string word){
		if(root==NULL){
			return false;
		}
		if(word.length()==0){
			return true;
		}
		int index= word[0];
		return searchPattern(root->children[index], word.substr(1));
	}
};

int main(){
    string text;
    getline(cin,text);
    Trie root;

    for(int i=0;i<text.length();i++){
        root.insertWord(text.substr(i));
    }

    string pattern;
    getline(cin,pattern);
    bool isPresent= root.searchPattern(pattern);
    if(isPresent){
        cout<<"pattern exists"<<endl;
    }
    else{
        cout<<"pattern does not exist"<<endl;
    }
    
    return 0;
}