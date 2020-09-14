// 738. Monotone Increasing Digits
//
// https://leetcode.com/problems/monotone-increasing-digits/
// Given a non-negative integer N, find the largest number that is less than or equal to N with monotone increasing digits.
//
//(Recall that an integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.)
#include <algorithm>
#include <unordered_map>
#include <map>
#include <iostream>
#include <cmath>
#include <set>
#include <list>
#include <stack>
using namespace std;

// deque solution
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if(N < 10)
            return N;
        deque<int> res;
        int numN = 0;
        int tmp;
        while(N){
            tmp = N % 10;
            if(!res.empty() and tmp > res.front()){
                res.clear();
                tmp -= 1;
            }
            res.push_front(tmp);
            N /= 10;
            numN += 1;
        }
        int ret = 0;
        for(auto &x: res){
            ret  = ret * 10 + x;
            numN--;
        }
        while(numN > 0){
            ret = ret * 10 + 9;
            numN--;
        }
        return ret;
    }
};

class Solution1 {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);

        int mark = str.size();

        for(int i = str.size() - 1; i > 0; i--)
        {
            if(str[i] < str[i - 1])
            {
                str[i - 1]--;

                mark = i;
            }
        }

        int res = 0;

        for(int i = 0; i < str.size(); i++)
        {
            if(i >= mark)
            {
                res = res * 10 + 9;
            }
            else
            {
                res = res * 10 + (str[i] - '0');
            }
        }

        return res;
    }
};

int main(){
    Solution t;
    cout << t.monotoneIncreasingDigits(123124) << endl;
}