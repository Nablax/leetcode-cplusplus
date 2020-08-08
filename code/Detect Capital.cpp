//https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/
//Given a word, you need to judge whether the usage of capitals in it is right or not.
//We define the usage of capitals in a word to be right when one of the following cases holds:
//All letters in this word are capitals, like "USA".
//All letters in this word are not capitals, like "leetcode".
//Only the first letter in this word is capital, like "Google".
//Otherwise, we define that this word doesn't use capitals in a right way.
#include <iostream>
using namespace std;
class Solution {
public:
    bool isCapital(char x){
        return x < 91 and x > 64;
    }
    bool detectCapitalUse(string word) {
        int c = word.length();
        auto mode = isCapital(word[0]) ? 0: 1;
        for(int i = 1; i < c; i++){
            if(mode == 0){
                if (!isCapital(word[i])){
                    if(i != 1){
                        return false;
                    }
                    mode = 2;
                }
            }
            else if(mode == 1 or mode == 2){
                if(isCapital(word[i])){
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {

}
