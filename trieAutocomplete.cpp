#include<iostream>
#include<string>
#include<vector>
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

	TrieNode* getWordNode(string word){
		return getWordNode(root,word);
	}

	TrieNode* getWordNode(TrieNode* root, string word){
		if(root==NULL){
			return NULL;
		}
		if(word.length()==0){
			return root;
		}
		int index= word[0]-'a';
		return getWordNode(root->children[index], word.substr(1));
	}

    void printAll(TrieNode* root,string output){
        if(root->isTerminal){
            cout<<output<<endl;
        }
        for(int i=0;i<26;i++){
            if(root->children[i]!=NULL){
                printAll(root->children[i],output+root->children[i]->data);
            }
        }
    }

    void autocomplete(string word){
        TrieNode* wordroot= getWordNode(word);
        if(wordroot!=NULL){
            printAll(wordroot,word);
        }
        else{
            cout<<"No such word"<<endl;
        }
    }
};

int main(){
    string text;
    vector<string> v;
    getline(cin,text);
    string temp="";
    for(int i=0;i<text.length();++i){
		
		if(text[i]==' '){
			v.push_back(temp);
			temp = "";
		}
		else{
			temp+=text[i];
		}
		
	}
	v.push_back(temp);
    // we have inserted each string in the text into a vector

    Trie root;
    for(auto letter:v){
        root.insertWord(letter);//inserting each word into the trie
    }

    string input;
    cin>>input;

    root.autocomplete(input);
    
    return 0;
}