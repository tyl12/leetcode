

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
    vector<string> result;
    vector<string> tmp;
    vector<string> restoreIpAddresses(string s) {
        backtracking(s);
        return result;
    }
    void backtracking(string substr){
        if (tmp.size() > 4){
            return;
        }
        if (tmp.size() == 4 && substr.empty()){
            //combine ip and return
            string combineStr;
            for(int i=0;i<4;i++){
                int val = stoi(tmp[i]);
                if (val > 255)
                    return;
                if (val>0 && tmp[i][0] == '0'){
                    return;
                }
                if (val==0 && tmp[i].size()>1){
                    return;
                }
                combineStr += tmp[i];
                if (i!=3)
                    combineStr+=".";
            }
            result.push_back(combineStr);
            printf("combineStr=%s\n", combineStr.c_str());
        }

        for(int len=1;len<=3;len++){
            if (len > substr.size())
                continue;
            string head = string(substr.begin(), substr.begin()+len);
            string tail = string(substr.begin()+len,substr.end());

            if (tmp.empty())
                cout<<"-----"<<endl;
            cout<<"head="<<head<<"  tail="<<tail<<endl;

            tmp.push_back(head);
            backtracking(tail);
            tmp.pop_back();
        }
    }

};

int main(){
    Solution s;
    s.restoreIpAddresses("2552550255");
    s.restoreIpAddresses("1234");
}