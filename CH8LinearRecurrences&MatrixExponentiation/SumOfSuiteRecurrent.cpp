#include <bits/stdc++.h>
#define int long long int
using namespace std;

int mod = 1e9;

/*
************SPP Spoj*********************
statement: Sequence (ai) of natural numbers is defined as follows:

ai = bi (for i <= k)
ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute am + am+1 + am+2 + ... + an for given m <= n and output it modulo a given positive integer p.

Appraoch: We can use matrix exponentiation to solve this problem in O(logn) time




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
        cout<<"Matrix "<<n<<" * "<<m<<"\n";
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
                    res.mat[i][j] += (mat[i][k] * other.mat[k][j])%mod;
                    res.mat[i][j]%=mod;
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

void solve(){
    int k;
    cin>>k;
    int b[k],c[k];
    for(int i = 0; i < k; i++){
        cin >> b[i];
    }
    for(int i = 0; i < k; i++){
        cin >> c[i];
    }
    int m,n,p;
    cin>>m>>n>>p;
    mod = p;
    Mat T(k+1,k+1);
    for(int i = 1;i<k+1;i++){
        T.mat[0][i]=c[i-1]%p;
        T.mat[1][i]=c[i-1]%p;
    }
    T.mat[0][0]=1;
    for(int i=2;i<k+1;i++){
        T.mat[i][i-1] = 1;
    }
    Mat F(k+1,1);
    for(int i=k;i>=1;i--){
        F.mat[i][0]=b[k-i]%p;
        F.mat[0][0]= (F.mat[0][0]+F.mat[i][0])%p;
    }

    int sum1=0,sum2=0;

    if(m<=k){
        for(int i=0;i<m-1;i++){
            sum1= (sum1+b[i]%p)%p;
        }
    }else{
        Mat Temp = T;
        Temp = T^(m-1-k);
        Temp = Temp*F;
        sum1 = Temp.mat[0][0];
    }
    if(n<=k){
        for(int i=0;i<n;i++){
            sum2= (sum2+b[i]%p)%p;
        }
    }else{
        Mat Temp = T;
        Temp = T^(n-k);
        Temp = Temp*F;
        sum2 = Temp.mat[0][0];
    }

    cout<<(sum2-sum1 )%mod<<"\n";




    
};
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
1
5
1 2 3 4 5 
1 2 3 4 5 
1 6 10000000


7
2
1 1
1 1
2 6 10000000
5
1 2 3 4 5 
1 2 3 4 5 
2 4 10000000
5
1 2 3 4 5 
1 2 3 4 5 
2 5 10000000
5
1 2 3 4 5 
1 2 3 4 5 
1 5 10000000
5
1 2 3 4 5 
1 2 3 4 5 
1 6 10000000
5
1 2 3 4 5 
1 2 3 4 5 
10 15 10000000
5
1 2 3 4 5
1 2 3 4 5 
3 3 10000000


*/