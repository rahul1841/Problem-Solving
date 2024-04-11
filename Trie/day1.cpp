Q1: Implement Trie

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie* children[26];
    bool isEnd;
    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* current = this;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (current->children[ch - 'a'] == NULL) {
                current->children[ch - 'a'] = new Trie();
            }
            current = current->children[ch - 'a'];
        }
        current->isEnd = true;
    }
    
    bool search(string word) {
         Trie* current = this;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (current->children[ch - 'a'] == NULL) {
                return false;
            }
            current = current->children[ch - 'a'];
        }
        if (current->isEnd == true)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
         Trie* current = this;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            if (current->children[ch - 'a'] == NULL) {
                return false;
            }
            current = current->children[ch - 'a'];
        }
        return true;
    }
};

Q2: Replace word

#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    TrieNode *child[26];
    bool isEnd;
    
    TrieNode(){
        this->isEnd = false;
        for(int i=0; i<26; i++) this->child[i]= NULL;
    }
};

class Solution {
public:
    TrieNode *newNode;
    string check(string word){
        TrieNode *t = newNode;
        string s = "";
        
        for(auto i : word){
            if(!t->child[i-'a']) break;
            s += i;
            t = t->child[i-'a'];
            if(t->isEnd) return s;
        }
        return word;
    }
    void insert(string word){
        TrieNode *temp = newNode;
        
        for(auto l : word){
            if(!temp->child[l-'a']) temp->child[l-'a'] = new TrieNode();
            temp = temp->child[l-'a'];
        }
        
        temp->isEnd = true;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        newNode = new TrieNode();
        for(auto s : dictionary){
            insert(s);
        } 
        stringstream ss(sentence);
        string word = "", ans="";
        
        while(ss>>word){
            ans += check(word);
            ans += ' ';
        }
        ans.pop_back();
        
        return ans;
    }
};