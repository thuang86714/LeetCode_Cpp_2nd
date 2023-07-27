class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //credit to its_vishal_7575
        //TC O(m*n)
        int n = matrix.size();
        int m = matrix[0].size();

        unordered_set<int> setRow;
        unordered_set<int> setCol;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    setRow.insert(i);
                    setCol.insert(j);
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(setRow.count(i) > 0 || setCol.count(j) > 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isColZero = false;
        bool isRowZero = false;
        for (int i = 0; i < matrix.size(); i++){//check the first column, but dont turn others just yet
            if(matrix[i][0]==0){
                isColZero = true;
                break;
            }
        }
        for(int i= 0; i < matrix[0].size(); i++){//check the first row, but dont turn others just yet
            if(matrix[0][i]==0){
                isRowZero = true;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); i++){//check except the first row and column
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++){//process except the first row and column
            for (int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if (isColZero){//process the first column
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0]=0;
            }
        }
        if (isRowZero){
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[0][i]=0;
            }
        }
    }
};