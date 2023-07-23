#include <bits/stdc++.h>

using namespace std;

/*
    Staement: Find the nth fibonacci number
    Solution: We can use matrix exponentiation to solve this problem in O(logn) time
    We know that the nth fibonacci number is given by the following recurrence:
    F(n) = F(n-1) + F(n-2)
    F(1) = 1
    F(2) = 1
    We can write this as a matrix equation:
    [F(n)] = [1 1] * [F(n-1)]
    [F(n-1)]   [1 0]   [F(n-2)]
    We can use matrix exponentiation to solve this problem in O(logn) time
    We can write the above equation as:
    [F(n)] = [1 1]^(n-1) * [F(1)]
    [F(n-1)]   [1 0]       [F(0)]

*/
class Mat {
public:
    int n, m;
    vector<vector<int>> mat;
    Mat(int n, int m){
        this->n = n;
        this->m = m;
        mat.resize(n, vector<int>(m, 0));
    }
    void identity(){
        for(int i = 0; i < n; i++){
            mat[i][i] = 1;
        }
    }

    void print(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Mat operator*(const Mat &other){
        Mat res(n, other.m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < other.m; j++){
                for(int k = 0; k < m; k++){
                    res.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return res;
    }

    Mat operator^(int b){
        Mat res(n, m);
        res.identity();
        Mat a = *this;
        while(b > 0){
            if(b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }

    Mat operator+(const Mat &other){
        Mat res(n, m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return res;
    }
};

int Fibonnaci(int n){
    Mat a(2, 2);
    a.mat[0][0] = 1;
    a.mat[0][1] = 1;
    a.mat[1][0] = 1;
    n-=2;
    a = a^n;
    return a.mat[0][0] + a.mat[0][1];
}


int main(){
    int n;
    cin >> n;
    cout << Fibonnaci(n) << endl;
    return 0;
}