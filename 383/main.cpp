#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> pool;
        for (int i = 0;i<ransomNote.size();i++){
            char s = ransomNote[i];
            auto search = pool.find(s);
            if (search != pool.end()){
                search->second += 1;
            }
            else{
                pool[s] = 1;
            }
        }

        for (int j =0; j<magazine.size(); j++){
            auto m = magazine[j];
            auto search = pool.find(m);
            if (search != pool.end()){
                search->second -= 1;
            }
        }

        for (auto &t : pool){
            if (t.second > 0){
                printf("remain: %c, %d\n", t.first, t.second);
                return false;
            }
        }
        return true;
    }
    bool canConstruct2(string ransomNote, string magazine) {
        int pool[26] = {0};
        for (auto t:pool){
            printf("%d,",t);
        }printf("\n");
        for (int i = 0;i<ransomNote.size();i++){
            char s = ransomNote[i];
            int index = s-'a';
            pool[index] += 1;
        }
        for (auto t:pool){
            printf("%d,",t);
        }printf("\n");
        for (int j =0; j<magazine.size(); j++){
            auto m = magazine[j];
            int index = m-'a';
            pool[index] -= 1;
        }

        for (int k=0;k<26;k++){
            if (pool[k] > 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string ransomNote = "abcdefx";
    string magazine =   "abcsdsdwsefxasfx";
    Solution s;
    auto m = s.canConstruct2(ransomNote, magazine);
    printf("result: %d\n", m);
    return 0;
}


