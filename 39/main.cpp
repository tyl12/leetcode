
#include <cstdint>
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
#include <deque>
#include <functional>
#include <algorithm>
#include <cmath>
#include <utility>
#include <numeric>
using namespace std;

class Solution {
public:

    int targetSum=0;
    int sum = 0;
    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        targetSum = target;
        backtracking(candidates, 0);
        return result;
    }

    void backtracking(vector<int>& candidates, int index){
        if (sum == targetSum){
            result.push_back(tmp);
            return;
        }
        if (sum > targetSum){
            return;
        }
        
        //for (int i:candidates){
        for (int i=index;i<candidates.size();i++){
            int val = candidates[i];
            sum += val;
            tmp.push_back(val);
            backtracking(candidates, i);
            sum -= val;
            tmp.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<int> candidates = vector<int>({1,2,3,4,5,6,7,8,9});
    s.combinationSum(candidates, 20);

    for (auto u:s.result){
        for (auto v:u){
            printf("%d,",v);
        }
        printf("\n");
    }
}