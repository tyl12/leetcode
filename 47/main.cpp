
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
    vector<bool> flags;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        flags = vector<bool>(nums.size(), false);
        backtracking(nums, flags);
        return result;
    }

    void backtracking(vector<int>& nums, vector<bool>& flags){

        if (intermediate.size()==nums.size()){
            result.push_back(intermediate);
            return;
        }

        vector<int> tmp;
        for(int i=0;i<nums.size();i++){
            if (flags[i]){
                continue;
            }
            if (find(tmp.begin(), tmp.end(), nums[i]) == tmp.end()){
                tmp.push_back(nums[i]);
                intermediate.push_back(nums[i]);
                flags[i]=true;
                backtracking(nums, flags);
                flags[i]=false;
                intermediate.pop_back();
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> data({1,2,2,3,3,3,4,5,5,6});
    auto result = s.permuteUnique(data);

    for_each(result.begin(), result.end(),[](auto v){
        for_each(v.begin(),v.end(), [](auto s){
            printf("%d,", s);
        });
        printf("\n");
    });
}