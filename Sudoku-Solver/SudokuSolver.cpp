// desc: CPP code to solve sudoku puzzle.

#include <iostream>
#include <vector>
using namespace std;

//Prints Sudoku
void printSudoku(vector<vector<char>> sudoku, string str){
    cout<< str<< endl;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<< sudoku[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< endl;
}

//My logic
bool isValid(char k, vector<vector<char>> A, int x, int y){
    for(int t=0; t<9; t++){
        //Validation For Row
        if(A[t][y]==k){
            return false;
        }
        //Validation For Column
        if(A[x][t]==k){
            return false;
        }
        //Validation For Sub-grid
        if(A[(x/3)*3+t/3][(y/3)*3+t%3]==k){
            return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &A){
    for(int y=0; y<9; y++){
        for(int x=0; x<9; x++){
            if(A[x][y]=='.'){
                for(char k='1'; k<='9'; k++){
                    if(isValid(k,A,x,y)){
                        A[x][y]=k;
                        if(solveSudoku(A))
                            return true;
                    }
                }
                A[x][y]='.';
                return false;
            }
        }
    }
    return true;
}

int main(){
    //Sudoku declaration
    vector<vector<char>> sudoku={
        {'5','3','.','.','7','.','.','.','.'}, 
        {'6','.','.','1','9','5','.','.','.'}, 
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'}, 
        {'4','.','.','8','.','3','.','.','1'}, 
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'}, 
        {'.','.','.','4','1','9','.','.','5'}, 
        {'.','.','.','.','8','.','.','7','9'}
    };
    printSudoku(sudoku, "Question: ");

    solveSudoku(sudoku);
    printSudoku(sudoku, "Solved sudoku: ");

    return 0;
}