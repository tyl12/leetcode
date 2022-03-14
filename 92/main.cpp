
#include <vector>
#include <iostream>
using namespace std;

int testfunc(vector<int>& nums, int target){
    int n = nums.size();
    if (n == 0)
        return 0;
    int i = 0, j = 0;
    int sum = nums[0];
    int len = INT32_MAX;
    while(true){
        printf("-> %d, %d, len=%d, sum=%d\n", i,j,len, sum);
        if (sum < target){
            if (j == n-1)
                break;
            j++;
            sum += nums[j];
        }
        else if (sum >= target){
            if ( (j-i+1) < len){
                len = j-i+1;
                printf("index: %d, %d; len=%d\n", i,j, len);
            }

            if (i<j){
                sum -= nums[i];
                i++;
            }else if (i==j){
                if (i==n-1)
                    break;
                i++;j++;
                sum = nums[i];
            }
        }
    }
    return len == INT32_MAX ? 0:len;
}

int testfunc2(vector<int>& nums, int target){
    int n = nums.size();
    if (n == 0)
        return 0;
    int i = 0, j = 0;
    int sum = 0;
    int len = INT32_MAX;

    for (int j=0;j<n;j++){
        sum += nums[j];
        while (sum >= target){
            if (j-i+1 < len){
                
                len = (j-i+1);
                printf("index: %d, %d; len=%d\n", i,j, len);
            }
            sum -= nums[i];
            i++;
        }
    }
    return len == INT32_MAX ? 0:len;
}

int main(void){
    //vector<int> nums = {1,2,3,4,5,6,7,8,9};
    vector<int> nums = {1,11,7,4,5,6,7,8,9};
    int val = 11;
    auto ret = testfunc(nums, val);
    cout<<ret<<endl;
}