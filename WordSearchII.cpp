//
// Created by 梁栋 on 2019-04-28.
//
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

class TrieMap{
public:
    unordered_map<char, TrieMap*> unordered_map1; // 当前节点的子节点
    char val;   // 当前节点的值
    int num; // 当前节点出现多少次
    bool isEnd; // 表示当前节点是不是End
    TrieMap(char v){
        this->val = v;
        this->num = 1;
        this->isEnd = false;
    }
    TrieMap(){
        // root节点初始化
        this->isEnd = false;
    }
    void insert(string str){
        if(str == "")
            return;
        TrieMap* root = this;
        for(auto c: str){
            if(root->unordered_map1[c] == NULL){
                root->unordered_map1[c] = new TrieMap(c);
            }else{
                root->unordered_map1[c]->num += 1;
            }
            root = root->unordered_map1[c];
        }
        root->isEnd = true;
    }
    bool hasStr(string str){
        // 判断有没有该字符串
        TrieMap* root = this;
        for(auto c: str){
            if(root->unordered_map1[c] == NULL)
                return false;
            root = root->unordered_map1[c];
        }
        return root->isEnd;
    }
    bool hasPerfix(string substr){
        // 判断有没有前缀
        TrieMap* root = this;
        for(auto c: substr){
            if(root->unordered_map1[c] == NULL)
                return false;
            root = root->unordered_map1[c];
        }
        return true;
    }
};

class Trie {

public:
    Trie* letters[26];
    bool isEnd;
    char c;
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
    bool hasStr(string word) {
        Trie* root = this;
        for(auto c:word){
            if(root->letters[c-'a'] == NULL)
                return false;
            root = root->letters[c-'a'];
        }
        return root->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool hasPerfix(string prefix) {
        Trie* root = this;
        for(auto c:prefix){
            if(root->letters[c-'a'] == NULL)
                return false;
            root = root->letters[c-'a'];
        }
        return true;
    }
};
class Solution {
public:
    int dxs[4] = {1, 0, -1, 0};
    int dys[4] = {0, 1, 0, -1};
    bool isValid(int x, int y, int m, int n){
        if(0 <= x && x < m && 0 <= y && y < n)
            return true;
        return false;
    }

    bool findWordsBase(vector<vector<char>>& board, bool* visits, int x, int y, int m, int n, string string1,
            Trie*& root, set<string>& set_res){
        if(!root->hasPerfix(string1))
            return false;
        if(root->hasStr(string1)){
            set_res.insert(string1);

            // return true;
        }
        for(int i=0;i<4;i++){
            int new_x = x + dxs[i];
            int new_y = y + dys[i];
            if(isValid(new_x, new_y, m, n) && !visits[new_x * n + new_y]){
                visits[new_x * n + new_y] = true;
                findWordsBase(board, visits, new_x, new_y, m, n, string1 + board[new_x][new_y],
                        root, set_res);
                visits[new_x * n + new_y] = false;
            }
        }
        return false;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> set_res;
        Trie* root = new Trie();
        for(auto s: words){
            root->insert(s);
        }
        int m = (int) board.size();
        if(m == 0)
            return {};
        int n = (int) board[0].size();
        bool visits[m*n];
        memset(visits, false, sizeof(visits));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                visits[i*n + j] = true;
                string cur_init = "";
                cur_init = cur_init + board[i][j];
                findWordsBase(board, visits, i, j, m, n, cur_init, root, set_res);
                visits[i*n + j] = false;
            }
        }
        vector<string> res(set_res.size());
        copy(set_res.begin(), set_res.end(), res.begin());
        return res;
    }
    static void solution(){
        vector<vector<char> > board = {
                {'a','b'},
                {'a','a'}

        };
        vector<string> words = {"aba","baa","bab","aaab","aaa","aaaa","aaba"};
        Solution solution1;
        vector<string> res = solution1.findWords(board, words);
        for(auto s: res){
            cout<<s<<endl;
        }
    }
};