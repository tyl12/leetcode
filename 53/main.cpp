

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
    vector<int> result;

    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = INT32_MIN;
        vector<int> tmp;
        for (int i=0;i<nums.size();i++){
            tmp.push_back(nums[i]);

            sum += nums[i];
            printf("val=%d, sum=%d, max=%d\n", nums[i], sum, max);
            if (sum > max){
                max = sum;
                result = tmp;
            }
            if (sum < 0){
                sum = 0;
                tmp.clear();
            }
        }
        return max;
    }
};

int main(){
    Solution s;
    vector<int> nums{-3,-4,1,2,3,4,5,-9,-8,-5,9,2,-6};
    auto res = s.maxSubArray(nums);
    cout<<res<<endl;

    for_each(s.result.begin(), s.result.end(), [](auto m){
        cout<<m<<",";
    });
    cout<<endl;

    return 0;
}