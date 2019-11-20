//
// Created by Liang on 2019-08-30.
//

#include <iostream>
#include <vector>
#include <sstream>


/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
std::string audioMatch(std::vector<std::string>& list1, std::vector<std::string>& list2, int x) {

}

/******************************结束写代码******************************/

void split(std::string& input_str, std::vector<std::string>& output_list) {
    std::istringstream tmp_stream(input_str);
    std::string tmp_str;
    while (getline(tmp_stream, tmp_str, ',')) {
        output_list.push_back(tmp_str);
    }
}
class Solution{
public:
    void static solution(){
        std::string s1;
        std::cin >> s1;

        std::string s2;
        std::cin >> s2;

        int x = 0;
        std::cin >> x;

        std::vector<std::string> list1;
        std::vector<std::string> list2;
        split(s1,list1);
        split(s2,list2);

        std::string res = audioMatch(list1, list2, x);
        std::cout << res << std::endl;
    }
};
//int main() {
//    std::string s1;
//    std::cin >> s1;
//
//    std::string s2;
//    std::cin >> s2;
//
//    int x = 0;
//    std::cin >> x;
//
//    std::vector<std::string> list1;
//    std::vector<std::string> list2;
//    split(s1,list1);
//    split(s2,list2);
//
//    std::string res = audioMatch(list1, list2, x);
//    std::cout << res << std::endl;
//
//    return 0;
//}