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

void TreyArch(int Trey, int Arch, int n) {
    int temp;
    bool hasTrey, hasArch;
    for(int i = 1; i <= n; i++){
        hasTrey = false, hasArch = false, temp = i;
        if(Trey != 0) hasTrey = ((temp % Trey) == 0);
        if(Arch != 0) hasArch = ((temp % Arch) == 0);

        while(temp and (!hasTrey or !hasArch)){
            if(temp % 10 == Trey) hasTrey = true;
            if(temp % 10 == Arch) hasArch = true;
            temp /= 10;
        }
        if(i > 1) std::cout<< " ";
        if(hasTrey) std::cout<< "Trey";
        if(hasArch) std::cout<< "Arch";
        if(!hasArch and !hasTrey) std::cout << i;
    }
}

int maxTickets(vector<int> tickets) {
    if(tickets.empty()) return 0;
    std::sort(std::begin(tickets), std::end(tickets));
    int maxTick = 1, countTick = 1;
    for(int i = 1; i < tickets.size(); i++){
        if(std::abs(tickets[i] - tickets[i - 1]) <= 1){
            countTick++;
        }
        else{
            maxTick = std::max(maxTick, countTick);
            countTick = 1;
        }
    }
    return std::max(maxTick, countTick);
}

int main(){
    TreyArch(9, 8, 20);
}