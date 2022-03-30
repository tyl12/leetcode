

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

    vector<int>data;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }

    void backtracking(vector<int>& nums, int index){
        if (index >= nums.size())
            return;
        
        // if (index == 0){
        //     result.push_back(data);
        //     return;
        // }
        
        for (int i=index;i<nums.size();i++){
            printf("pushback %d\n", nums[i]);
            data.push_back(nums[i]);

            result.push_back(data);
            backtracking(nums, i+1);
            data.pop_back();
        }
    }


    /*
    vector<vector<int>> result;

    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty())
            return result;

        int cnt = 1;
        for (cnt=0;cnt<=nums.size();cnt++){

            getSubset(nums, cnt);
        }
        result.push_back(vector<int>());
        return result;
    }

    void getSubset(vector<int>& nums, int cnt){
        vector<int> res;
        if (cnt<=0 || cnt > nums.size()){
            return;
        }

        backtracking(nums, 0, cnt);//index=0~nums.size()-1
    }

    vector<int> tmp;
    void backtracking(vector<int>& nums, int index, int cnt){
        if (tmp.size() >= cnt){

            result.push_back(tmp);
            return;
        }
        for (int i=index;i<nums.size();i++){
            tmp.push_back(nums[i]);
            backtracking(nums, i+1, cnt);
            tmp.pop_back();
        }
    }
    */
};

int main(){
    Solution s;
    auto data = vector<int>{1,2,3,4,5,6};
    auto result = s.subsets(data);

    for_each(result.begin(), result.end(),[](auto v){
        for_each(v.begin(),v.end(), [](auto s){
            printf("%d,", s);
        });
        printf("\n");
    });
}