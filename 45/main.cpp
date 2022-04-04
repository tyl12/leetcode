

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
    int canJump(vector<int>& nums) {
        int beginIndex = 0;
        int endIndex = beginIndex;
        int endIndexNext = endIndex;
        if (nums.size() == 1)
            return 0;

        int cnt = 0;
        while(true){
            //printf("beginIndex=%d, endIndex=%d \n", beginIndex, endIndex);

            for (int i=beginIndex;i<=endIndex;i++){
                int val = nums[i];
                endIndexNext = endIndexNext > (i+val)?endIndexNext:(i+val);
                if (endIndexNext >= nums.size()-1){
                    cnt++;
                    return cnt;
                }
            }
            if (endIndexNext <= endIndex)
                return -1;
            else if (endIndexNext > endIndex){
                cnt++;

                beginIndex = endIndex+1;
                endIndex = endIndexNext;
            }
        }
    }

};

int main(){
    //vector<int> nums{13,1,2,2,1,2,1,1,3,1,2,1,3,2,1};
    //vector<int> nums{0};
    vector<int> nums{1,1,1,1,1};
    //vector<int> nums{2,3,1,1,4};
    Solution s;
    auto res = s.canJump(nums);
    cout<<res<<endl;
    return 0;
}