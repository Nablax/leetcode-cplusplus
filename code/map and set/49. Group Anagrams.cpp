//49. Group Anagrams
//
//https://leetcode.com/problems/group-anagrams/
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
//
//
//
//Example 1:
//
//Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//Example 2:
//
//Input: strs = [""]
//Output: [[""]]
//Example 3:
//
//Input: strs = ["a"]
//Output: [["a"]]

#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, int> dic;
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