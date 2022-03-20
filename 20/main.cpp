#include <string>
#include <stdio.h>
#include <stack>
using namespace std;

class Solution {
public:
    bool compareMatch(stack<char>& cont, char h){
        if (cont.empty())
            return false;
        auto m1 = cont.top();
        cont.pop();
        printf("#pop %c, want %c\n", m1,h );
        if (m1 != h) {
          return false;
        }
        return true;
    }
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0;i<s.size();i++){
            char m = s[i];
            char dest;
            switch (m){
                case '[':
                case '{':
                case '(':
                    printf("#push %c\n", m);
                    st.push(m);
                    continue;
                case ')':
                    dest = '(';
                    break;
                case ']':
                    dest = '[';
                    break;
                case '}':
                    dest = '{';
                    break;
                default:
                    break;
            }
            if (!compareMatch(st, dest)) {
              return false;
            }
        }
        if (st.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    string m = "()";
    Solution s;
    auto res = s.isValid(m);
    printf("result: %d\n", res);
}