// Stone Game IV
// https://leetcode.com/problems/stone-game-iv/
// Alice and Bob take turns playing a game, with Alice starting first.
//
//Initially, there are n stones in a pile.  On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.
//
// Also, if a player cannot make a move, he/she loses the game.
//
// Given a positive integer n. Return True if and only if Alice wins the game otherwise return False, assuming both players play optimally.

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
using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        std::vector<bool> states(n + 1, false);
        for(int i = 1; i <= n; i++){
            for(int k = 1; k * k <= i; k++){
                if(!states[i - k * k]){
                    states[i] = true;
                    break;
                }
            }
        }
        return states[n];
    }
};