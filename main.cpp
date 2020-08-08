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
