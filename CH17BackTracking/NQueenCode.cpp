#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    problem statement: print all the ways to place n queens in a n*n chessboard and print the number of ways
    input: 4
    output:
    . Q . .
    . . . Q
    Q . . .
    . . Q .

    . . Q .
    Q . . .
    . . . Q
    . Q . .

    2

    approach: backtracking
    we will put a queen in each row
    for each row we have n choices to place the queen
    we can place the queen in a column if the column is empty and the diagonals are empty

    we can check if the column is empty by using an array col
    col[i] represents the ith column
    if col[i] is 0 then the ith column is empty
    if col[i] is 1 then the ith column is not empty


    we can check if the diagonals are empty by using two arrays diag1 and diag2
    diag1[i] represents the diagonal from top left to bottom right
    diag2[i] represents the diagonal from top right to bottom left
    if we are at row i and column j then the diagonal from top left to bottom right will be diag1[i+j]
    if we are at row i and column j then the diagonal from top right to bottom left will be diag2[n-1-(i-j)]

    if diag1[i+j] is 0 then the diagonal from top left to bottom right is empty
    if diag1[i+j] is 1 then the diagonal from top left to bottom right is not empty


    if we are not at the last row then we will try to place the queen in each column if it is possible
    if we are at row i and column j then we will place the queen in the ith row and jth column by setting board[i][j]='Q'
    we will mark the ith column as not empty by setting col[j]=1
    we will mark the diagonal from top left to bottom right as not empty by setting diag1[i+j]=1
    we will mark the diagonal from top right to bottom left as not empty by setting diag2[n-1-(i-j)]=1

    if our solution is correct then we will reach the last row
    if we reach the last row then we will print the board and return 1

    if we reach the last row we will not backtrack because we want to print all the solutions
    if the current solution is not correct then we will backtrack also 
    
    backtracking will be as follows
    we will mark the ith column as empty by setting col[j]=0
    we will mark the diagonal from top left to bottom right as empty by setting diag1[i+j]=0
    we will mark the diagonal from top right to bottom left as empty by setting diag2[n-1-(i-j)]=0
    we will remove the queen from the ith row and jth column by setting board[i][j]='.'


    time complexity: O(n^n) or O(n!) // there are n choices for each row or you can see it [EXPONENTIAL TIME COMPLEXITY]
    space complexity: O(n)


*/


void printBoard(vector<vector<char>> &board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int  solveNqueens(int row,vector<vector<char>> &board,int n,int col[],int diag1[],int diag2[]){
    //base case
    if(row==n){        
        printBoard(board);
        cout<<"\n";
        return 1;
    }

    //recursive case
    int ways = 0;
    for(int i=0;i<n;i++){
        if(col[i]==0 && diag1[row+i]==0 && diag2[n-1-(i-row)]==0){
            col[i]=1;
            diag1[row+i]=1;
            diag2[n-1-(i-row)]=1;

            board[row][i]='Q';
            ways+=solveNqueens(row+1,board,n,col,diag1,diag2);


            //backtrack
            board[row][i]='.';
            col[i]=0;
            diag1[row+i]=0;
            diag2[n-1-(i-row)]=0;
        }
    }
    return ways;
}

void solve(){
    int n;
    cin>>n;
    int col[n]={0};
    int diag1[2*n-1]={0};
    int diag2[2*n-1]={0};
    vector<vector<char>> board(n,vector<char>(n,'.'));
    int ways = solveNqueens(0,board,n,col,diag1,diag2);
    cout<<"Total ways: "<<ways<<"\n";
    
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}