

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
    bool canJump2(vector<int>& nums) {
        int beginIndex = 0;
        int endIndex = beginIndex;
        int endIndexNext = endIndex; 
        while(true){
            //printf("beginIndex=%d, endIndex=%d \n", beginIndex, endIndex);

            for (int i=beginIndex;i<=endIndex;i++){
                int val = nums[i];
                endIndexNext = endIndexNext > (i+val)?endIndexNext:(i+val);
                if (endIndexNext >= nums.size()-1)
                    return true;
            }
            if (endIndexNext <= endIndex)
                return false;
            else if (endIndexNext > endIndex){
                beginIndex = endIndex+1;
                endIndex = endIndexNext;
            }
        }
    }
    bool canJump1(vector<int>& nums) {
        int beginIndex = 0;
        int endIndex = beginIndex+1;
        int endIndexNext = endIndex; 
        while(true){
            //printf("beginIndex=%d, endIndex=%d \n", beginIndex, endIndex);

            for (int i=beginIndex;i<endIndex;i++){
                int val = nums[i];
                endIndexNext = endIndexNext > (i+val+1) ? endIndexNext:(i+val+1);
                if (endIndexNext >= nums.size())
                    return true;
            }
            if (endIndexNext <= endIndex)
                return false;
            else if (endIndexNext > endIndex){
                beginIndex = endIndex;
                endIndex = endIndexNext;
            }
        }
    }
    bool canJump(vector<int>& nums) {
        int range = 0;
        for (int i=0;i<=range;i++){
            int val = nums[i];
            range = range > (i+val) ? range:(i+val);
            if (range >= nums.size()-1)
                return true;
        }
        return false;
    }
};

int main(){
    //vector<int> nums{13,1,2,2,1,2,1,1,3,1,2,1,3,2,1};
    //vector<int> nums{0};
    vector<int> nums{2,3,1,1,4};
    Solution s;
    auto res = s.canJump(nums);
    cout<<res<<endl;
    return 0;
}