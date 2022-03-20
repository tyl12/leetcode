#include <string>
#include <stdio.h>
#include <stack>
#include <unistd.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <functional>
using namespace std;


bool cmp(const pair<int, int>& m1, const pair<int, int>& m2){
    return (m1.second <= m2.second);
}



auto my_comp = [](const pair<int, int>& m1, const pair<int, int>& m2)->bool {
    return (m1.second <= m2.second);
};
// decltype(cmp) s1;
// decltype(my_comp) s2;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> intMap;
        for (auto i:nums){
            auto r = intMap.find(i);
            if ( r == intMap.end()){
                intMap[i]=1;
            }else{
                r->second += 1;
            }
        }

        //priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(my_comp)> que{my_comp};
        //priority_queue<pair<int,int>, vector<pair<int,int> >, decltype(&cmp) > que{cmp};
        //priority_queue<pair<int,int>, vector<pair<int,int> >, decltype(cmp)* > que{cmp};
        priority_queue<pair<int,int>, vector<pair<int,int> >, function<decltype(cmp)> > que{cmp};

        for (auto [k,v]:intMap){

            cout<<k<<":"<<v<<endl;
            que.push(pair<int,int>(k,v));
        }
        int cnt = 0;
        vector<int> result;
        while(cnt++ < k){
            cout<<" -> "<<que.top().first;

            result.push_back(que.top().first);
            que.pop();
        }
        return result;
    }
};

int main(){
    decltype(cmp) func;

    Solution s;
    vector<int> nums={1,2,2,2,5,5,5,5,5,6,7,8,6,5,5,4,8,8,8,8,8,8,8};
    int k = 3;
    s.topKFrequent(nums, k);
    return 0;
}