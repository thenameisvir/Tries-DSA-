#include<iostream>
using namespace std;
class TrieNode{
  public:
  char value;
  TrieNode* children[26];
  bool isTerminal;

  TrieNode(char val){
    this->value = val;
    for(int i=0;i<26;i++){
      children[i] = NULL;
    }
    this->isTerminal = false;
  }
};
void insertWord(TrieNode* root,string word){
  // cout<<word<<" "<<endl;
  if(word.length()==0){
    root->isTerminal = true;
    return;
  }

  char ch = word[0];
  int index = ch-'a';
  TrieNode* child;
  if(root->children[index]!=NULL){
    child = root->children[index];

  }
  else{
    child = new TrieNode(ch);
    root->children[index] = child;

  }

  insertWord(child,word.substr(1));
}
int main()
{
  TrieNode* root = new TrieNode('-');
  insertWord(root,"abc");
  insertWord(root,"abcde");
  insertWord(root,"abcda");
  insertWord(root,"abcdr");
  insertWord(root,"abcdrt");
}