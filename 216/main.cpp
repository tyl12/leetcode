
#include <cstdint>
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
/*
    vector<vector<int>> result;
    vector<int> tmp;
    //vector<int> data;
    vector<vector<int>> combine(int n, int k) {
        // for(int i=1;i<=n;i++){
        //     data.push_back(i);
        // }
        // for (int i=1;i<=n;i++){
        //     backtracking(n, k, i);
        // }
        backtracking(n, k, 1);
        return result;
    }

    void backtracking(int n, int k, int startIndex){

        if (k==0){
            // if (startIndex>n)
            //     return;
            //tmp.push_back(startIndex);
            result.push_back(tmp);
            //tmp.pop_back();
            return;
        }

        for(int i=startIndex;i<=n;i++){
            tmp.push_back(i);
            backtracking(n, k-1, i+1);
            tmp.pop_back();
        }

    }
*/

    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(9, k, n, 0);
        return result;
    }

    void backtracking(int n, int k, int sumVal, int startIndex){
        if (k==0){
            int s = accumulate(tmp.begin(), tmp.end(), 1);
            if (s == sumVal)
                result.push_back(tmp);
            return;
        }

        for(int i=startIndex;i<=n;i++){
            tmp.push_back(i);
            backtracking(n, k-1, sumVal, i+1);
            tmp.pop_back();
        }

    }
    
    /*
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        backtracking(n, k, 1, tmp);
        return result;
    }

    void backtracking(int n, int k, int startIndex, vector<int> data){
        if (k==0){
            result.push_back(data);
            return;
        }

        for(int i=startIndex;i<=n;i++){
            auto tmp = data;
            tmp.push_back(i);
            backtracking(n, k-1, i+1,tmp);
            //tmp.pop_back();
        }

    }
    */
};

int main()
{
    Solution s;
    auto result = s.combinationSum3(5, 20);
    for (auto v: result){
        for (auto e: v){
            printf("%d,",e);
        }
        printf("\n");
    }
}

