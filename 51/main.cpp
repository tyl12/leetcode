
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


class Solution2 {
public:
    int _n;
    vector<vector<string>> result;

    vector<vector<string>> solveNQueens(int n) {
        _n = n;
        vector<vector<int>> boards;
        vector<int> tmp(n, 0);
        tmp.reserve(n);
        boards.reserve(n);
        for (int i=0;i<n;i++){
            boards.push_back(tmp);
        }
        //cout<<"---1"<<endl;
        backtracking(boards, 0);

        // cout<<"## backtracking done"<<endl;
        // for (int i=0;i<result.size();i++){
        //     showVector(result[i]);
        // }
        // cout<<"---2"<<endl;

        return result;
    }

    void backtracking(vector<vector<int>>& boards, int row){
        //cout<<" backtracking row = "<<row<<endl;
        if (row == _n){
            vector<string> oneresult;
            for (int m =0;m<_n;m++){
                string oneline ="";
                vector<int> columns = boards[m];
                for (int s=0;s<_n;s++){
                    if (columns[s]){
                        oneline+="Q";
                    }
                    else{
                        oneline+=".";
                    }
                }
                //cout<<oneline<<endl;
                oneresult.push_back(oneline);
            }
            result.push_back(oneresult);
            return;
        }

        for (int j = 0; j < _n; j++) {
            //cout << "check row: " << row << " col: " << j << endl;
            if (!isValidPoint(boards, row, j)) {
                continue;
            }
            //cout << "insert " << row << " , " << j << endl;
            boards[row][j] = 1;
            backtracking(boards, row + 1);
            boards[row][j] = 0;
        }

    }

    bool isValidPoint(vector<vector<int>>& boards, int row, int col){
        for (int i=0;i<row;i++){
            if (boards[i][col]){
                return false;
            }
        }
        for (int k=0;k<row;k++){
            int j = col - k - 1;
            int i = row - k - 1;
            if (i>=0 && j>=0){
                if (boards[i][j])
                    return false;
            }
        }
        for (int k=0;k<row;k++){
            int j = col + k + 1;
            int i = row - k - 1;
            if (i>=0 && j>=0 && i<_n && j<_n){
                if (boards[i][j])
                    return false;
            }
        }
        return true;
    }
    void showVector(vector<string>& m){
        for_each(m.begin(), m.end(), [](auto v){
            cout<<v<<" -> ";
        });
        cout<<endl;
    }
};


class Solution {
public:
    int _n;
    vector<vector<string>> result;

    vector<vector<string>> solveNQueens(int n) {
        _n = n;

        //char* boards = new (char*)[n];

        //int* mp = new int*[n];

        int** boards = new int*[n];

        for (int i=0;i<n;i++){
            boards[i] = new int[n];
            memset(boards[i], 0, n*sizeof(int));
        }
        


        // vector<vector<char>> boards;
        // vector<char> tmp(n, 0);
        // tmp.reserve(n);
        // boards.reserve(n);
        // for (int i=0;i<n;i++){
        //     boards.push_back(tmp);
        // }
        //cout<<"---1"<<endl;
        backtracking(boards, 0);

        // cout<<"## backtracking done"<<endl;
        // for (int i=0;i<result.size();i++){
        //     showVector(result[i]);
        // }
        // cout<<"---2"<<endl;

        return result;
    }

    void backtracking(int** boards, int row){
        //cout<<" backtracking row = "<<row<<endl;
        if (row == _n){
            vector<string> oneresult;
            for (int m =0;m<_n;m++){
                string oneline ="";
                int* columns = boards[m];
                for (int s=0;s<_n;s++){
                    if (columns[s]){
                        oneline+="Q";
                    }
                    else{
                        oneline+=".";
                    }
                }
                cout<<oneline<<endl;
                oneresult.push_back(oneline);
            }
            result.push_back(oneresult);
            return;
        }

        for (int j = 0; j < _n; j++) {
            //cout << "check row: " << row << " col: " << j << endl;
            if (!isValidPoint(boards, row, j)) {
                continue;
            }
            //cout << "insert " << row << " , " << j << endl;
            boards[row][j] = 1;
            backtracking(boards, row + 1);
            boards[row][j] = 0;
        }

    }

    bool isValidPoint(int** boards, int row, int col){
        for (int i=0;i<row;i++){
            if (boards[i][col]){
                return false;
            }
        }
        for (int k=0;k<row;k++){
            int j = col - k - 1;
            int i = row - k - 1;
            if (i>=0 && j>=0){
                if (boards[i][j])
                    return false;
            }
        }
        for (int k=0;k<row;k++){
            int j = col + k + 1;
            int i = row - k - 1;
            if (i>=0 && j>=0 && i<_n && j<_n){
                if (boards[i][j])
                    return false;
            }
        }
        return true;
    }
    void showVector(vector<string>& m){
        for_each(m.begin(), m.end(), [](auto v){
            cout<<v<<" -> ";
        });
        cout<<endl;
    }
};

int main(){
    Solution s;
    const int n = 4;
    auto res = s.solveNQueens(n);

    return 0;
}
