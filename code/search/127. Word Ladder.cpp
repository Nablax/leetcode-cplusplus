// 127. Word Ladder
// Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:
//
//Only one letter can be changed at a time.
//Each transformed word must exist in the word list.
//Return 0 if there is no such transformation sequence.
//
//
//
//Example 1:
//
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
//Output: 5
//Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
//Example 2:
//
//Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
//Output: 0
//Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

// Using BFS to solve the problem

#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>
#include <cmath>
#include <set>
#include <list>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <bitset>
#include <memory>
#include <numeric>
using namespace std;


class Solution {
public:
    int compareString(const string &x, const string &y){
        int diff = 0;
        for(int i = 0; i < x.size(); i++){
            if(x[i]!=y[i]) diff++;
            if(diff > 1) break;
        }
        return diff;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool hasEnd = false;
        for(auto &x: wordList){
            if(!hasEnd and x == endWord) {
                hasEnd = true;
            }
        }
        if(!hasEnd) return 0;
        wordList.push_back(beginWord);
        int todoStart = wordList.size() - 1, todoEnd = wordList.size();
        int res = 1, newTodoStart, i = 0;
        while(todoStart < todoEnd){
            newTodoStart = todoStart;
            res++;
            while(todoStart < todoEnd){
                todoEnd--;
                i = 0;
                while(i < newTodoStart){
                    if(compareString(wordList[todoEnd], wordList[i]) == 1){
                        if(wordList[i] == endWord) return res;
                        std::swap(wordList[--newTodoStart], wordList[i]);
                    }
                    else{
                        i++;
                    }
                }
            }
            todoStart = newTodoStart;
        }
        return 0;
    }
};

int main(){
    Solution c;
    std::vector<std::string> testcase = {"ted","tex","red","tax","tad","den","rex","pee"};
    cout << c.ladderLength("red", "tax", testcase);
}