
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> generateMatrix(int n) {

    int total = 0;
    int step = n-1;
    int i=0,j=0;

    int val = 1;
    vector<vector<int>> mat;
    mat.reserve(n);
    for (int row=0;row<n;row++){
        mat[row].reserve(n);
    }
    if (n == 1){
        mat[0][0]=1;
        return mat;
    }
    while(true){
        int cnt=0;
        for(cnt = 0;cnt<step; cnt++){
            //printf("fill row: %d, %d, %d\n", i,j, val);
            mat[i][j] = val++;
            j++;
        }
        for(cnt = 0;cnt<step; cnt++){
            //printf("fill col: %d, %d, %d\n", i,j, val);
            mat[i][j] = val++;
            i++;
        }
        for(cnt = 0;cnt<step; cnt++){
            //printf("fill row: %d, %d, %d\n", i,j, val);
            mat[i][j] = val++;
            j--;
        }
        for(cnt = 0;cnt<step; cnt++){
            //printf("fill col: %d, %d, %d\n", i,j, val);
            mat[i][j] = val++;
            i--;
        }
        i++;
        j++;

        step -= 2;
        if (step == 0){
            //printf("fill center: %d, %d, %d\n", i,j, val);
            mat[i][j] = val;
            break;
        }
        if (step == -1){
            break;
        }
    }
    return mat;
}

int main(void){
    for (int n=1;n<5;n++){
        auto mat = generateMatrix(n);
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                printf("\t%d",mat[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
