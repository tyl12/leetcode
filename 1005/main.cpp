

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
    int largestSumAfterKNegations_wront(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // for_each(nums.begin(), nums.end(), [](auto m){
        //     cout<<m<<endl;
        // });

        int i = 0;
        int cnt = 0;
        while(cnt < k && i < nums.size()){
            if (nums[i] <= 0){
                nums[i] = -nums[i];
                i++;
                if (i == nums.size())
                    i = nums.size()-1;
            }else{
                int remainK = k - cnt;
                if (i==0){
                    if ( remainK%2 == 1){
                        nums[i] = -nums[i];
                    }  
                }
                else{
                    if ( nums[i] >= abs(nums[i-1]) ){
                        if ( remainK%2 == 1){
                            nums[i-1] = -nums[i-1];
                        }
                    }
                    else{
                        if ( remainK%2 == 1){
                            nums[i] = -nums[i];
                        }
                    }
                }
                break;
            }
            cnt++;
        }
        for_each(nums.begin(), nums.end(), [](auto m){
            cout<<m<<",";
        });
        cout<<endl;
        auto res = accumulate(nums.begin(), nums.end(), 0);

        return res;
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](auto a, auto b){
            if (abs(a) > abs(b))
                return true;
            return false;
        });
        int cnt=0;
        int i = 0;
        while(cnt<k){
            if (i==nums.size()-1){
                nums[i] = -nums[i];
                cnt++;
            }
            else{
                if (nums[i]<0){
                    nums[i] = -nums[i];
                    cnt++;
                }
                i++;
            }
        }

        for_each(nums.begin(), nums.end(), [](auto m){
            cout<<m<<",";
        });
        cout<<endl;
        auto res = accumulate(nums.begin(), nums.end(), 0);

        return res;
    }
};



int main(){
    // vector<int> nums{-3,-5,-9,1,3,4};
    // int k = 3;

    // vector<int> nums{-3,-5,1,3};
    // int k = 1;

    // vector<int> nums{4,2,3};
    // int k = 1;

    vector<int> nums{-3,-5,-3};
    int k = 4;

    Solution s;
    auto res = s.largestSumAfterKNegations(nums, k);
    cout<<res<<endl;
    return 0;
}