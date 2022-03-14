#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int calculateRes(int num, int* statistics, int cnt){
        //memset(statistics, 0, cnt);
        int remain = num;
        int result = 0;
        while(remain > 0){
            int res = remain%10;
            remain = remain/10;
            statistics[res]+=1;
            //printf("# %d, ", res);
            result += res*res;
        }
        return result;
    }
    bool isSame(int* statistics, int* statisticsInit, int cnt){
        for (int i=1;i<cnt;i++){ //TODO:
            if (statistics[i] != statisticsInit[i]){
                return false;
            }
        }
        return true;
    }
    void showStat(int* stat, int cnt){
        printf("---->\n");
        for (int i=0;i<cnt;i++){
            printf("%d:%d\n", i, stat[i]);
        }
        printf("=====\n");
    }

    // bool isHappy(int n) {
    //     int statisticsInit[10] = {0};
    //     int result = calculateRes(n, statisticsInit, 10);
    //     unordered_set<int> pool;
    //     pool.insert(result)



    //     showStat(statisticsInit, 10);
    //     //printf("=> result=%d\n", result);
    // //return 0;
    //     while(true){
    //         int statistics[10] = {0};

    //         result = calculateRes(result,  statistics, 10);
    //         showStat(statistics, 10);

    //         printf("result=%d\n", result);
    //         if (result == 1){
    //             printf("isHappy\n");
    //             return true;
    //         }
    //         if (isSame(statistics, statisticsInit, 10)){
    //             printf("not happy\n");
    //             return false;
    //         }
    //     }
    // }
    int calculateRes2(int num){
        //memset(statistics, 0, cnt);
        int remain = num;
        int result = 0;
        while(remain > 0){
            int res = remain%10;
            remain = remain/10;
            result += res*res;
        }
        return result;
    }
    bool isHappy(int n) {
        
        unordered_set<int> pool;
        int result = n;
        pool.insert(result);
        while(true){
            result = calculateRes2(result);
            printf("%d\n", result);
            if (result == 1){
                printf("isHappy\n");
                return true;
            }
            auto p = pool.find(result);
            if (pool.end() == p){
                pool.insert(result);
            }
            else{
                printf("not happy\n");
                return false;
            }
        }
    }
};

int main(){
    printf("########################################\n");
    Solution s;
    s.isHappy(234);
    return 0;
}