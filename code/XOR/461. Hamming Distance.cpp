// Hamming Distance
// https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int b = x ^ y;
        int num = 0;
        while(b > 0){
            num += (b != (b >> 1) << 1);
            b = b >> 1;
        }
        return num;
    }
};

int main(){
    Solution c;
    c.hammingDistance(1, 4);
}