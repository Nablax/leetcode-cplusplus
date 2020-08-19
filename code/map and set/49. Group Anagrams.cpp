//49. Group Anagrams
//
//https://leetcode.com/problems/group-anagrams/
//Given an array of strings, group anagrams together.

#include <map>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::map<std::string, int> dic;
        std::vector<std::vector<std::string>> res;
        for(int i = 0 ;i< strs.size(); i++){
            auto tmpX = strs[i];
            std::sort(tmpX.begin(), tmpX.end());
            if(dic.find(tmpX) != dic.end()){
                res[dic[tmpX]].push_back(strs[i]);
            }
            else{
                std::vector<std::string> tmpRes = {strs[i]};
                dic[tmpX] = res.size();
                res.push_back(tmpRes);
            }
        }
        return res;
    }
};