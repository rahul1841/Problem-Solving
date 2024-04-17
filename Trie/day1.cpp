Q1: Implement Trie

struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return ( links[ch-'a'] != NULL);
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
    
};

// TC for all is O(length)
class Trie {
private: 
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            // not contain key
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i<prefix.length(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

Q2: Sum of Prefix Scores of Strings

struct Node{
    Node* links[26];
    int prefix = 0;
    
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    void incPrefix(){
       prefix ++; 
    }
    
    int getPrefix(){
        return prefix;
    }
};

class Trie{
    
    private:
    
    Node* root;
    
    public:
    
    Trie(){
        root = new Node();
    }
    
    void insert (string &word){
        Node* node = root;
        for(int i = 0; i<word.size(); i++){
        if(!node->containsKey(word[i])){
            node->put(word[i], new Node());
        }
            node = node->get(word[i]);
            node->incPrefix();
        }
    }
    
    int countPrefix(string &word){
        Node* node = root;
        int ans = 0;
        for(int i = 0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                ans += node->getPrefix();
            }else{
                break;
            }
        }
        return ans;
    }
    
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> ans(n);
        Trie trie;
        for(int i = 0 ; i< n; i++){
            trie.insert(words[i]);
        }
        for(int i = 0; i<n; i++){
            ans[i] = trie.countPrefix(words[i]);
        }
        return ans;
    }
};




Q3: Replace word

struct Node{
    Node* links[26];
    bool isEnd = false;
    
    bool containsKey(char ch){
    return (links[ch-'a'] != NULL);
    }

    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
    return links[ch-'a'];
    }

    
    void setEnd(){
        isEnd = true;
    }
    
    bool getEnd(){
        return isEnd;
    }
};

class Trie{
    private: Node* root;
    
    public: 
    Trie(){
        root = new Node();
    }
    
void insert(string &word){
    Node* node = root;
    for(int i = 0; i < word.size(); i++){
        if(!node->containsKey(word[i])){
            node->put(word[i], new Node());
        }
        node = node->get(word[i]);
    }
    node->setEnd();
}

    
    string find(string &word){
        Node* node = root;
        string ans = "";
        for(int i = 0; i<word.size(); i++){
            if(node->getEnd()) break;
            if(node->containsKey(word[i])){
                ans += word[i];
                node = node->get(word[i]);
            }
            else{
                break;
            }
        }
        if(node->getEnd()){
            return ans;
        }
        else{
            return "";
        }
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size();
        int m = sentence.size();
        
        Trie trie;
        
        for(int i = 0; i<n; i++){
            trie.insert(dictionary[i]);
        }
        
        string temp = "";
        string ans = "";
for(int i = 0; i < m; i++){
    if(sentence[i] != ' '){
        temp += sentence[i];
    }
    else{
        string temp1 = trie.find(temp);
        if(temp1 == ""){
            ans += temp;
        }
        else{
            ans += temp1;
        }
        ans += ' ';
        temp = "";
    }
    if(i == m - 1){
        string temp1 = trie.find(temp);
        if(temp1 == ""){
            ans += temp;
        }
        else{
            ans += temp1;
        }
    }
}
        return ans;
    }
};