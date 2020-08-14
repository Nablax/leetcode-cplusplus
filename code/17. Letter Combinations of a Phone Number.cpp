// Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int getResLen(string s){
        int len = 1;
        for (auto x : s){
            if(x=='9' or x=='7')
                len *= 4;
            else
                len *= 3;
        }
        return len==1? 0:len;
    }
    void appendVector(vector<string> &a, string l, int partition){
        int len = l.size();
        int offset = partition * len;
        for(int i = 0; i < len; i++)
            for(int k = i * partition; k < a.size(); k+= offset)
                for(int j = 0; j < partition; j++){
                    a[k + j] += l[i];
                }
    }
    vector<string> letterCombinations(string digits) {
        savedSeq = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res(getResLen(digits));
        int partition = res.size();
        for(auto x : digits){
            string l = savedSeq[x - '0'];
            partition /= l.size();
            appendVector(res, l, partition);
        }
        return res;
    }
private:
    vector<string> savedSeq;
};