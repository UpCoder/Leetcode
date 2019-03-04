//
// Created by 梁栋 on 2018-12-16.
//
#include <string>
#include <iostream>
using namespace std;

class Solution3 {
public:
    bool is_palindome(string str, int start_index, int end_index){
        //判断str[start_index, end_index) 是不是回文字符串
//        if(start_index >= end_index){
//            return true;
//        }
//        if(s[start_index] == s[end_index - 1]){
//            return is_palindome(s, start_index + 1, end_index - 1);
//        }else{
//            return false;
//        }
          for(int s=start_index, e=end_index-1; s<=e; s++, e--){
              if(str[s] == str[e]){
                  continue;
              }else{
                  return false;
              }
          }
        return true;
    }
//    string longestPalindrome(string s){
//        //该算法的时间复杂度是O(N^3), 还可以继续优化
//        unsigned long len = s.length();
//        string res = "";
//        for(int size=len; size>0; size--){
//            for(int low=0; (low + size) <= len; low++){
//                string cur_str = s.substr(low, size);
//                if(is_palindome(cur_str, 0, size)){
//                    return cur_str;
//                }
//            }
//        }
//        return res;
//    }
    string longestPalindrome(string s){
        //该算法的时间复杂度是O(N^3), 还可以继续优化
        unsigned long len = s.length();
        int max_len = 0;
        string res = "";
        for(int i=0;i<len;i++){
            int low = i;
            int high = i;
            int target_low = low;
            int target_high = high;
//            cout<<target_low<<","<<target_high<<endl;
            while (low >=0 && high < len){
                if(s[low] == s[high]){
                    target_low = low;
                    target_high = high;
                    low --;
                    high ++;
                }else{
                    break;
                }
            }
            if((target_high - target_low + 1) > max_len){
                max_len = (target_high - target_low + 1);
                res = s.substr(target_low, max_len);
                // cout<<res<<endl;
            }
        }
        for(int i=0;i<len;i++){
            int low = i;
            int high = i + 1;
            bool find = false;
            int target_low = i;
            int target_high = i + 1;
            while (low >=0 && high < len){
                if(s[low] == s[high]){
                    target_low = low;
                    target_high = high;
                    find = true;
                    low --;
                    high ++;
                }else{
                    break;
                }
            }
            if(find && (target_high - target_low + 1) > max_len){
                max_len = (target_high - target_low + 1);
                res = s.substr(target_low, max_len);
                // cout<<res<<endl;
            }
        }
        return res;

    }
};
class LongestPalindromicSubstring {
public:
    static void test(){
        string x = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa";
// string x = "caba";
        string y = "cbbd";
        string z = "";
        Solution3 solution = Solution3();
//        cout<<solution.longestPalindrome(x)<<endl;
        cout<<solution.longestPalindrome(y)<<endl;
        cout<<solution.longestPalindrome(z)<<endl;
    }
};
