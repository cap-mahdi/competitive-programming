#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    statement: given a n*n board with some cells filled with numbers
    you have to fill the empty cells with numbers from 1 to n such that
    no number is repeated in any row or column or subgrid (sudoku rules)

    if there are multiple solutions then print all the solutions
    if there is no solution then print no solution
    

    approach: backtracking
    we will try to place every number in the empty cells if it is possible
    if we are at row i and column j then we will try to place the number k in the ith row and jth column by setting board[i][j]=k
    we will check if the number can be placed in the cell by using a function canPlace
    canPlace will check if the number is present in the row or column or subgrid

    if the current number didn't work then we will backtrack by setting board[i][j]=0 and trying the next number

    if we reach the end of the board then we will print the board and return true

    time complexity: O(n^m) // n choices for each cell and there are m empty cells
    space complexity: O(n*n)
*/

void printBoard(int matrix[][9],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool canPlace(int matrix[][9],int i,int j,int n,int number){
    //check if the number is present in the row or column
    for(int x=0;x<n;x++){
        if(matrix[x][j]==number || matrix[i][x]==number){
            return false;
        }
    }

    //check if the number is present in the subgrid
    int rn = sqrt(n); //length of the subgrid
    int sx = (i/rn)*rn; //starting x coordinate of the subgrid
    int sy = (j/rn)*rn; //starting y coordinate of the subgrid

    for(int x=sx;x<sx+rn;x++){
        for(int y=sy;y<sy+rn;y++){
            if(matrix[x][y]==number){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int matrix[][9],int i,int j,int n){
    //base case
    if(i==n){ //if we reach the end of the board
        printBoard(matrix,n);
        return true;
    }

    //recursive case
    //if we reach the end of the row then go to the next row
    if(j==n){
        return solveSudoku(matrix,i+1,0,n);
    }

    //if the cell is already filled we go to the next cell
    if(matrix[i][j]!=0){
        return solveSudoku(matrix,i,j+1,n);
    }

    //if the cell is empty
    //try to place every number in the cell
    for(int number=1;number<=n;number++){
        //check if the number can be placed in the cell


        if(canPlace(matrix,i,j,n,number)){
            matrix[i][j] = number;
            bool success = solveSudoku(matrix,i,j+1,n);
            if(success){
                return true;
            }
        }
    }
    matrix[i][j] = 0;
    return false;
}

void solve(){
    int n = 9;
    int matrix[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if(!solveSudoku(matrix,0,0,n)){
        cout<<"No solution exists\n";
    }

    
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}