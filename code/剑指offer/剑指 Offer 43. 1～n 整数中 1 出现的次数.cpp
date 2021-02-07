// 剑指 Offer 43. 1～n 整数中 1 出现的次数
//输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
//
//例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。
//
//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

// 思路一，双dp
class Solution {
public:
    int countDigitOne(int n) {
        int count10 = 10, curDig = n % 10, curNum = n % 10;
        //fn存储的是当前数字中的1的个数，例如51234，f4就是0-1234中包含1的个数
        //gn存储的是当前位数数字中1的个数，例如51234，g4就是0-9999中包含1的个数
        int fn = (curDig == 0? 0: 1), gn = 1, fnext;
        n = n / 10;
        while(true){
            fnext = 0;
            //对n我们每次取最后一位记作curdig
            curDig = n % 10;
            // curDig大于1时候，例如51234
            // 有递归式fn+1 =
            // fn (开头数字为5且包含1的数字，就是0-1234中包含1的个数)+
            // gn * curDig (对于开头数字为43210，刚好为5个，乘以0-9999中包含1的数字)+
            // count10 (开头数字为1，即10000-19999共10000个数字)
            if(curDig > 1){
                fnext += fn + gn * curDig + count10;
            }
            // curDig等于1时候，例如11234
            // 有递归式fn+1 =
            // curNum + 1 (因为开头为1，所以加上0000-1234共1235个数)
            // fn (0-1234中包含1的个数，此时开头为1)+
            // gn (0-9999中包含1的个数，此时开头为0)
            if(curDig == 1){
                fnext += curNum + 1 + fn + gn;
            }
            // curDig等于1时候，例如01234
            // 直接加上0-1234中包含1的数即可
            if(curDig == 0){
                fnext += fn;
            }
            fn = fnext;
            n /= 10;
            if(n == 0) break;
            curNum += curDig * count10;
            // 更新gn，1-999和1-9999的差距就在于往最高位补0-9所以乘10，补1的时候再单独算一次0-999共1000个数
            gn = gn * 10 + count10;
            count10 *= 10;
        }
        return fn;
    }
};

// 思路2，以54321为例
// 个位上每经过一次0~9循环1就出现一次，则个位上1出现的次数为5432+1次（若个位数为0，则1在个位上出现5432次）；
//
// 十位上，1出现的次数为543*10+1*10次（若十位数为1，则十位上1出现次数为543*10+2次）
//
// 百位上，1出现的次数为54*100+1*100次（若百位数为1，则百位上1出现次数为54*100+22次）；
//
// 千位上，1出现的次数为5*1000+1*1000次（若千位数为1，则千位上1出现次数为5*1000+322次）；
//
// 万位上，1出现次数为0*10000+1*10000次