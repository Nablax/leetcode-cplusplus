// Basic Calculator III
// https://leetcode.com/problems/basic-calculator-ii/

#include <vector>
#include <stack>
#include <string>
#include <iostream>

class Solution {
public:
    bool isNum(char x) {
        if ( x <= '9' and x >= '0')
            return true;
        return false;
    }
    int getPrior(char x){
        if(x == '+' or x == '-')
            return 1;
        if(x == '*' or x == '/')
            return 2;
        return -999;
    }
    void cal(int &top, int num, char sym){
        if(sym == '+'){
            top += num;
        }
        else if(sym == '-'){
            top -= num;
        }
        else if(sym == '*'){
            top *= num;
        }
        else if(sym == '/'){
            top /= num;
        }
    }
    bool isPrior(char top, char in){
        if(top == '(' or in == '(')
            return false;
        return getPrior(top) >= getPrior(in);
    }
    void operStack(std::stack<int> &nums, std::stack<char> &symbol){
        if(nums.empty())
            return;
        int tmp = nums.top();
        nums.pop();
        cal(nums.top(), tmp, symbol.top());
        symbol.pop();
    }
    int calculate(std::string s) {
        std::stack<int> nums;
        std::stack<char> symbol;
        bool befIsChar = true;
        for(auto x: s){
            if(isNum(x)){
                if(befIsChar){
                    befIsChar = false;
                    nums.push(x - '0');
                }
                else{
                    nums.top() *= 10;
                    nums.top() += x - '0';
                }
                continue;
            }
            else if(x == ')'){
                while(!symbol.empty() and symbol.top()!='(')
                    operStack(nums, symbol);
                symbol.pop();
            }
            else if(x != ' '){
                while(!symbol.empty() and isPrior(symbol.top(), x))
                    operStack(nums, symbol);
                symbol.push(x);
            }
            befIsChar = true;
        }
        while(!symbol.empty()){
            operStack(nums, symbol);
        }
        return nums.top();
    }
};

int main(){
    std::string s ="1*2-3/4+5*(6-7)*8+9/10";
    Solution c;
    std::cout<<c.calculate(s);
}