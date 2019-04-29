//
// Created by 梁栋 on 2019-04-29.
//
// 构建字典树，可以方便的查询前缀和是否有字符串出现
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Trie {
private:
    Trie* letters[26];
    bool isEnd;
    char c;
public:
    /** Initialize your data structure here. */
    Trie() {
        this->isEnd = false;
        memset(letters, 0, sizeof(letters));
    }
    Trie(char c){
        this->c = c;
        this->isEnd = false;
        memset(letters, 0, sizeof(letters));
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(auto c: word){
            if(root->letters[c-'a'] == NULL){
                root->letters[c-'a'] = new Trie(c);
            }
            root = root->letters[c-'a'];
        }
        root->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for(auto c:word){
            if(root->letters[c-'a'] == NULL)
                return false;
            root = root->letters[c-'a'];
        }
        return root->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for(auto c:prefix){
            if(root->letters[c-'a'] == NULL)
                return false;
            root = root->letters[c-'a'];
        }
        return true;
    }
};
class Solution{
public:
    static void solution(){
        Trie* root = new Trie();
        root->insert("abcdefg");
        root->insert("efg");
        root->insert("abc");
        cout<<root->search("ab")<<endl;
    }
};
