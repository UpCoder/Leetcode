//
// Created by 梁栋 on 2019-04-28.
//
#include <vector>
#include <map>
#include <iostream>
using namespace std;
struct Node{
    int x;
    int y;
    char c;
    bool available;
    Node(int x, int y, int c){
        this->x = x;
        this->y = y;
        this->c = c;
        this->available = true; // 一开始都是可用的
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
    bool existBase(vector<vector<char>>& board, string word, int cur_idx, bool* visits, int x, int y,
            const int& m, const int& n){
        if(cur_idx == word.length())
            return true;
        for(int i=0;i<4;i++){
            int new_x = x + dxs[i];
            int new_y = y + dys[i];
            if(isValid(new_x, new_y, m, n) && !visits[new_x * n + new_y] && board[new_x][new_y] == word[cur_idx]){
                // 当前位置合法，并且尚未有点加入
                visits[new_x * n + new_y] = true;
                if(existBase(board, word, cur_idx + 1, visits, new_x, new_y, m, n))
                    return true;
                visits[new_x * n + new_y] = false;

            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(m == 0 && word.length() == 0)
            return true;
        if(m == 0)
            return false;
        int n = board[0].size();
        bool visits[m * n];
        memset(visits, false, sizeof(visits));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    visits[i * n + j] = true;
                    if(existBase(board, word, 1, visits, i, j, m, n))
                        return true;
                    visits[i * n + j] = false;
                }
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for(auto s: words){
            if(exist(board, s)){
                res.push_back(s);
            }
        }
        return res;
    }
    static void solution(){
        vector<vector<char> > board = {
                {'A','B','C','E'},
                {'S','F','C','S'},
                {'A','D','E','E'}
        };
        string word = "ABCF";
        Solution solution1;
        cout<<solution1.exist(board, word)<<endl;
    }
};
