#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <string>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        for (int i=0;i<len/2;i++){
            auto tmp = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = tmp;
        }
    }
    string reverseStr(string s, int k) {
        
    }
};

int main(){
    Solution s;
    vector<char> data={'a','b','c','d','e'};
    s.reverseString(data);
    for (auto & t:data){
        printf("%c,", t);
    }
    printf("\n");
}