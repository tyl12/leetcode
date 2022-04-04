

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
    int findContentChildren(vector<int>& g, vector<int>& s) {//g child, s biscuit
        int childNum = g.size();
        int cookieNum = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;

        int j = cookieNum-1;
        for (int i=childNum-1;i>=0 && j>=0;i--){
            printf("child = %d, biscuit=%d\n", g[i], s[j]);
            if (g[i]<=s[j]){
                result++;
                j--;
            }
        }
        return result;
    }
};


int main(){
    Solution sol;
    vector<int> g{1,2,3,4,5,6};
    vector<int> s{3,4,6,7};
    auto res = sol.findContentChildren(g, s);
    printf("%d\n", res);
}