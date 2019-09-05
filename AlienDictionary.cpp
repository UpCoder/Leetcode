//
// Created by Liang on 2019-08-26.
//
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    bool dfs(int* graph, stack<int>& path, int * used, int cur_loc){
        for(int i=0;i<26;i++){
            if(i != cur_loc && used[i] == 0 && graph[cur_loc * 26 + i] == 1){
                // 该点没有遍历过，并且存在边
                used[i] = 2;
                graph[cur_loc * 26 + i] = 0;
                if(!dfs(graph, path, used, i))
                    return false;
            }
            if(i != cur_loc && used[i] == 2 && graph[cur_loc * 26 + i] == 1){
                // 该点正在遍历
                return false;
            }
        }
        // 该点遍历完成
        used[cur_loc] = 1;
        path.push(cur_loc);
        return true;
    }
    string alienOrder(vector<string>& words) {
        int graph[26*26];
        memset(graph, 0, sizeof(graph));
        int last_char = -1;
        for(auto str: words){
            char first_char = str[0];
            if(last_char != -1){
                if(last_char != (first_char-'a')){
                    graph[last_char * 26 + first_char-'a'] = 1;
                }
            }
            for(int i=1;i<str.length();i++){
                if(first_char == str[i]){
                    first_char = str[i];
                    continue;
                }
                graph[(first_char - 'a') * 26 + (str[i] - 'a')] = 1;
                first_char = str[i];
            }
            last_char = str[0] - 'a';
        }
        int used[26];
        memset(used, 0, sizeof(used));
        stack<int> path;
        used[words[0][0]-'a'] = 2;
        bool flag = dfs(graph, path, used, words[0][0]-'a');
        if(!flag)
            return "";
        string output = "";
        while(!path.empty()){
            output += char('a' + path.top());
            path.pop();
        }
        return output;
    }
    string alienOrderV2(vector<string>& words){
        int graph[26 * 26];
        memset(graph, 0, sizeof(graph));
        if(words.size() == 0)
            return "";
        int count_char[26];
        memset(count_char, 0, sizeof(count_char));
        for(auto word: words){
            for(auto c:word){
                graph[(c-'a') * 26 + (c-'a')] = 1;
                count_char[c-'a'] += 1;
            }
        }

        for(int i=0;i<words.size()-1;i++){
            for(int j=0;j<words[i].length() && j < words[i+1].length();j++){
                if(words[i][j] != words[i+1][j]){
                    graph[(words[i][j] - 'a') * 26 + words[i+1][j] - 'a'] = 1;
                    break;
                }else{
                    continue;
                }
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(graph[i*26 + j] == 1){
                    cout<<char(i + 'a')<<" -> "<<char(j + 'a')<<endl;
                }
            }
        }
        int used[26];
        memset(used, 0, sizeof(used));
        stack<int> path;
        for(int i=0;i<26;i++){
            if(count_char[i] > 0 && used[i] == 0){
                used[i] = 2;
                bool flag = dfs(graph, path, used, i);
                if(!flag)
                    return "";
                used[i] = 1;
            }

        }
        string output = "";
        while(!path.empty()){
            output += char('a' + path.top());
            path.pop();
        }
        return output;
    }
    static void solution(){
        vector<string> words = {
//                "wrt",
//                "wrf",
//                "er",
//                "ett",
//                "rftt",
                "zy",
                "zx"
        };
        Solution solution1;
        cout<<solution1.alienOrderV2(words)<<endl;
    }
};