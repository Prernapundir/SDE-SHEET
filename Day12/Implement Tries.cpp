

class Node{
    public:
    Node* links[26];
    bool flag=false;
   
    // check if word is present or not
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    
    // Insert the node at given word
    void put(char ch,Node* newNode){
        links[ch-'a']=newNode;
    }
    
    // get new referenc of the word
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    // set flag to true, if end of the word came
    void setEnd(){
        flag=true;
    }
    
    // check for the end of word , flag should be true for end
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
   
    
public:
    Trie() {
        root=new Node();
    }
    // Insert each char of word , start from root node
    // tc - O(n)
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    // Search fro gven word exists or not
    // tc- O(n)
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
     
    // check wheteher this prefix exits or not in trie
    // same like seach function , only diffrence is no need to check end of the word, just return true , if words end
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
