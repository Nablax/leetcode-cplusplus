#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
#include <sstream>
using namespace std;

void istreamtest(){
    string s = " 123 345";
    istringstream iss(s);
    ostringstream oss;
    while(iss>>s){
        oss<<s;
        oss<<" ";
    }
    cout<<oss.str();
}
void dequetest(){
    std::deque<int> dq;
    dq.push_back(1);
    cout<<dq[0];
    dq.pop_front();

    std::deque<int *> dq2;
    int *a = nullptr;
    dq2.push_back(a);
    cout<<dq[0];
}

void unordered_maptest(){
    std::unordered_map<int, int> dic;
    dic[1] = 1;
    dic[4] = 4;
    dic[3] = 3;
    dic[5] = 5;
    dic[2] = 2;
    for(auto &x: dic){
        cout<<x.first;
    }
}

void unordered_settest(){
    std::unordered_set<int> s1, s2, s3;
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);
//    cout<<(s1.find(1) != s1.end());
//    cout<<(s1.find(3) != s1.end());
    s2.insert(4);
    s2.insert(5);
    s2.insert(6);
    s2.insert(7);
    s2.insert(8);
    s2.insert(9);

    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s3, s3.begin()));
    cout<<s3.size()<<endl;
    s3.clear();

    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s3, s3.begin()));
    cout<<s3.size()<<endl;
    s3.clear();

    std::merge(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(s3, s3.begin()));
    cout<<s3.size()<<endl;
    s3.clear();
}

void min_elementtest(){
    std::vector<int> v = {6, 7, 3, 4, 5};
    std::cout<< *std::min_element(v.begin(), v.end());
}

void stdmovetest(){
    std::vector<int> res(10, 1);
    auto tmp = std::move(res[0]);
    std::cout << tmp << std::endl;
    std::cout << res[0] << std::endl;
    res[0] = 14;
    std::cout << tmp << std::endl;
    std::cout << res[0] << std::endl;

}




int testequalreturn(){
    int a = 0;
    return a = 114514;
}

int main(){
    stdmovetest();
}
