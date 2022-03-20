#include <string>
#include <stdio.h>
#include <stack>
#include <unistd.h>
#include <memory.h>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        cout<<s<<endl;
        int len = s.size();
        char* tmp = new char[len];
        int idx = 0;
        memset(tmp, 0, len);
        for (auto h:s){
            //cout<<"handle "<<h<<endl;
            if (idx == 0 || tmp[idx-1] != h){
                tmp[idx++] = h;
                //cout<<"push "<<h<<endl;                
                continue;
            }
            if (tmp[idx-1] == h){
                //cout<<"pop  "<<h<<endl;
                tmp[idx-1] = '\0';
                idx--;
            }
        }
        string result(tmp);
        delete[] tmp;
        return result;
    }
    string removeDuplicates2(string s) {
        cout<<s<<endl;
        deque<char> cont;
        for (auto h:s){
            if (cont.empty() || cont.back() != h){
                cont.push_back(h);
            }else{
                cont.pop_back();
            }
        }
        string result;
        for (auto h:cont){
            result.push_back(h);
        }
        return result;
    }
};

int main(){
    Solution s;
    cout<<s.removeDuplicates("abbcddeeghhge")<<endl;
}