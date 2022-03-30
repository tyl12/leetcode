


#include <cstdint>
#include <ostream>
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
    vector<vector<int>> result;
    vector<int> intermediate;
/*
    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(nums);
        return result;
    }

    void backtracking(vector<int>& nums){
        if (nums.empty()){
            result.push_back(intermediate);
            return;
        }
        for (int i=0;i<nums.size();i++){
            auto val = nums[i];
            vector<int> tmp(nums.begin(), nums.end());
            tmp.erase(tmp.begin()+i);
            intermediate.push_back(val);
            backtracking(tmp);
            intermediate.pop_back();
        }
    }
    */
    vector<bool> flag;

    vector<vector<int>> permute(vector<int>& nums) {
        flag = vector<bool>(nums.size(), false);
        backtracking(nums, flag);
        return result;
    }

    void backtracking(vector<int>& nums, vector<bool>& flag){
        if (intermediate.size() >= nums.size()){
            result.push_back(intermediate);
            return;
        }
        for (int i=0;i<nums.size();i++){
            if (flag[i]){
                continue;
            }
            auto val = nums[i];
            // vector<int> tmp(nums.begin(), nums.end());
            // tmp.erase(tmp.begin()+i);
            intermediate.push_back(val);

            flag[i]=true;
            backtracking(nums, flag);
            intermediate.pop_back();
            flag[i]=false;
        }
    }
};

int main(){
    Solution s;
    vector<int> data({1,2,3,4});
    auto result = s.permute(data);
    for_each(result.begin(), result.end(), [](auto v){
        for_each(v.begin(), v.end(), [](auto m){
            cout<<m<<",";
        });
        cout<<endl;
    });
}