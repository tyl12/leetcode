#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0] ){
            return 0;
        }
        if (target > *nums.end()){
            return nums.size();
        }

        return binarysearch(nums, 0, nums.size(), target);
        
    }
    
    int binarysearch(vector<int>& arr, int begin, int end, int target){
        if (begin == end)
            return begin;
        int idx = (begin + end)/2;
        
        if (arr[idx] == target)
            return idx;
        if (arr[idx] >target)
            return binarysearch(arr, 0, idx, target);
        if (arr[idx] < target)
            return binarysearch(arr, idx +1 , end, target);
        return -1;
    }
    
};

int main(){
    Solution s;
    //vector nums={1,2,3,4,5,6,7};
    vector<int> nums={2,3,4,5,8,9,10};
    int ret = s.searchInsert(nums, 12);
    cout<<ret<<endl;

    for_each(nums.begin(), nums.end(), [=](auto val){
        cout<<val<<endl;
    });
    

}