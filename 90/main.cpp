

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
#include <set>
#include <unordered_set>
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

    vector<int>data;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }

/*
    void backtracking(vector<int>& nums, int index){
        result.push_back(data);

        if (index >= nums.size())
            return;

        vector<int> tmp;

        for (int i=index;i<nums.size();i++){

            if (find(tmp.begin(), tmp.end(), nums[i]) != tmp.end()){
                //printf("already used: %d\n",nums[i]);
                continue;
            }
            tmp.push_back(nums[i]);
            //printf("pushback %d\n", nums[i]);
            data.push_back(nums[i]);

            backtracking(nums, i+1);

            data.pop_back();
        }
    }
*/

    void backtracking(vector<int>& nums, int index){
        result.push_back(data);//TODO: import for  the position.

        if (index >= nums.size())
            return;

        unordered_set<int> tmp;

        for (int i=index;i<nums.size();i++){

            if (tmp.find(nums[i]) != tmp.end()){
                continue;
            }
            tmp.insert(nums[i]);

            //printf("pushback %d\n", nums[i]);
            data.push_back(nums[i]);

            backtracking(nums, i+1);

            data.pop_back();
        }
    }

};

int main(){
    Solution s;
    auto data = vector<int>{2,2,1,2,2,3};
    auto result = s.subsetsWithDup(data);

    for_each(result.begin(), result.end(),[](auto v){
        for_each(v.begin(),v.end(), [](auto s){
            printf("%d,", s);
        });
        printf("\n");
    });
}