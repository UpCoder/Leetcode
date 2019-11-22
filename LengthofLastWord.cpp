//
// Created by 梁栋 on 2019-11-22.
//
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        if(len == 0)
            return 0;
        while(s[len-1] == ' '){
            s = s.substr(0, len-1);
            len = len-1;
        }
        int countSpace = 0;
        for(auto c: s){
            if(c == ' ')
                countSpace += 1;
        }
        if(countSpace == len)
            return 0;
        int result = len;
        cout<<"result init is "<<result<<endl;
        cout<<len<<endl;
        for(int i=0;i<len;i++){
            if(countSpace == 0){
                break;
            }
            if(s[i] == ' '){
                countSpace --;
                result --;
            }else{
                result--;
            }
        }
        return result;
    }
    static void solution(){
        Solution solution1;
        cout<<solution1.lengthOfLastWord("a ");
    }
};