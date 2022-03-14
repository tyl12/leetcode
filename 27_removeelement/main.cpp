
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int removeElement1(vector<int>& nums, int val) {
        vector<int> records; 
        for (int i = 0;i<nums.size();i++){
            if (nums[i] == val){
                records.push_back(i);
            }
        }
        /*
        cout<<"matched index"<<endl;
        for_each(records.begin(), records.end(), [](int v){cout<<v<<" ";});
        cout<<endl;
        */
        int backup_idx = nums.size() - 1;
        for (auto i:records){
            tag:
            bool updated = false;
            if (find(records.begin(),records.end(), backup_idx) == records.end()){
                //cout<<"switch index"<<i<<","<<backup_idx<<endl;
                nums[i] = nums[backup_idx];
                updated = true;
            }
            backup_idx--;
            if (backup_idx <= i)
                break;
            if (!updated)
                goto tag;
        }
        return nums.size()-records.size();
    }
    int removeElement3(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;
        int idx_begin = 0;
        int idx_end = nums.size()-1;

        while(true){
            //printf("begin: end: %d, %d\n", idx_begin, idx_end);
            if (idx_begin >= idx_end){
                if (nums[idx_begin] == val)
                    return idx_begin;
                else
                    return idx_begin + 1;
            }

            if (nums[idx_begin] == val){
                if ( nums[idx_end] != val){
                    //printf("swap %d -> %d\n", idx_begin, idx_end);
                    nums[idx_begin] = nums[idx_end];
                    nums[idx_end] = val;
                    idx_begin++;
                }
                idx_end--;
                //continue;
            }
            else{
                idx_begin++;
            }
        }
    }

    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i  = 0;
        while(true){
            if (i >= n)
                return i;
            if (nums[i] == val){
                nums[i] = nums[n-1];
                n--;
            }
            else {
                i++;
            }
        }
    }

};


int main(){
    Solution s;
    //vector<int> nums={};
    //vector<int> nums={5,5,5,5,5};
    //vector<int> nums={1,2,5,5,5,5,5};
    //vector<int> nums={5,5,5,5,1,2,3,5,6,7,8,5,5};
    //vector<int> nums={5,5,5,5,1,2,3};
    //vector<int> nums={2,3,4,5,5,8,9,10};
    //vector<int> nums={2,3,4,5};
    //vector<int> nums={2,3,5,5};
    //vector<int> nums={4,5};
    int ret = s.removeElement(nums, 5);
    cout<<"---return:"<<ret<<endl;
    for_each(nums.begin(), nums.begin()+ret, [](int v){cout<<v<<" ";});
    cout<<endl;
   
}