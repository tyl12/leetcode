
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
    map<int,string> phone;
    vector<string> letterCombinations(string digits) {
        phone[2]="abc";
        phone[3]="def";
        phone[4]="ghi";
        phone[5]="jkl";
        phone[6]="mno";
        phone[7]="pqrs";
        phone[8]="tuv";
        phone[9]="wxyz";
        backtracing(digits, 0);
        return result;
    }
    vector<string> result;

    string tmp;
    void backtracing(string digits, int index){//index = 0,1,2,3

        if (index >= digits.size()){
            result.push_back(tmp);
            return;
        }

        char c = digits[index];
        int num = c - '0';
        string letters = phone[num];
        for (char m:letters){
            tmp.push_back(m);
            backtracing(digits, index+1);
            tmp.pop_back();
        }
    }

};

int main(){
    Solution s;
    auto result = s.letterCombinations("2345");
    for (auto m:result){
        cout<<m<<endl;
    }
}