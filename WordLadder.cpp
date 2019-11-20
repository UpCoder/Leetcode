//
// Created by Liang on 2019-08-16.
//
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool meetChangeCond(string beginWord, string endWord){
        bool equal = true;
        for(int i=0;i<beginWord.length();i++){
            if(beginWord[i] == endWord[i])
                continue;
            if(equal == false)
                return false;
            equal = false;
        }
        if(equal)
            return false;
        return true;
    }

    bool ladderLengthCore(string current_word, string endWord, const vector<string>& wordList, bool* used, int len, int& res){
        if(current_word == endWord){
            res = min(len,res);
            return true;
        }
        for(int i=0;i<wordList.size();i++){
            if(used[i])
                continue;
            if(meetChangeCond(current_word, wordList[i])){
                used[i] = true;
                ladderLengthCore(wordList[i], endWord, wordList, used, len + 1, res);
                used[i] = false;
            }else{
                continue;
            }
        }
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> filtered;
        for(auto str: wordList){
            if(str.length() != beginWord.length()){
                continue;
            }else{
                filtered.push_back(str);
            }
        }

        int num_words = wordList.size();
        bool used[num_words];
        memset(used, false, sizeof(used));
        int res = num_words + 10;
        for(int i=0;i<num_words;i++){
            if(meetChangeCond(beginWord, wordList[i])){
                used[i] = true;
                ladderLengthCore(wordList[i], endWord, wordList, used, 1, res);
                used[i] = false;
            }
        }
        if(res != (num_words + 10)){
            return res + 1;
        }
        return 0;
    }
    int ladderLengthBFS(string beginWord, string endWord, vector<string>& wordList) {
        int num_words = wordList.size();
        bool is_connected[num_words][num_words];
        bool used[num_words];
        memset(is_connected, false, sizeof(is_connected));
        memset(used, false, sizeof(used));
        for(int i=0;i<num_words;i++){
            for(int j=0;j<i;j++){
                bool is_meet_condition = meetChangeCond(wordList[i], wordList[j]);
                if(is_meet_condition){
                    is_connected[i][j] = true;
                    is_connected[j][i] = true;
                }
            }
        }
        queue<pair<int, int>> queue1;
        for(int i=0;i<num_words;i++){
            if(meetChangeCond(wordList[i], beginWord)){
                queue1.push(pair<int, int>(i, 1));
                used[i] = true;
            }
        }
        while(!queue1.empty()){
            pair<int, int> cur_pair = queue1.front();
            queue1.pop();
            if(wordList[cur_pair.first] == endWord){
                return cur_pair.second + 1;
            }
            for(int i=0;i<num_words;i++){
                if(used[i] == false && is_connected[cur_pair.first][i]){
                    pair<int, int> new_pair = pair<int, int>(i, cur_pair.second + 1);
                    used[i] = true;
                    queue1.push(new_pair);
                }
            }
        }
        return 0;
    }
    static void solution(){
        vector<string> wordList = {"hot","dot","dog","lot","log", "cog"};
        string beginWord = "hit";
        string endWord = "cog";
        Solution solution1;
        cout<<solution1.ladderLengthBFS(beginWord, endWord, wordList)<<endl;
    }
};