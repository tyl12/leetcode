
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
    vector<vector<string>> result;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        backtracking(s);
        return result;
    }

    bool isReverse(string str){
        //cout<<"isReverse:"<<str<<endl;
        for(int i=0;i<str.size()/2;i++){
            if (str[i] != str[str.size()-i-1]){
                return false;
            }
        }
        return true;
    }
    void backtracking(string s){
        if (s.size() == 0){
            //if (isReverse(path)){
                result.push_back(path);
            //}
            return;
        }
        for (int len=1;len<=s.size();len++){
            string head = s.substr(0,len);
            //cout<<"head="<<head<<endl;
            if (!isReverse(head))
                continue;

            path.push_back(head);
            if (len==s.size())
                backtracking(string());
            else
                backtracking(s.substr(len));
            path.pop_back();
        }
    }
};

int main(){
    Solution s;
    auto result = s.partition("aabbcdefgf");
    for (auto v:result){
        for(auto m:v){
            cout<<m<<",";
        }
        cout<<endl;
    }
}