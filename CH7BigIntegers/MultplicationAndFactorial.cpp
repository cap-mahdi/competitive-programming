#include <bits/stdc++.h>

using namespace std;

string multiply(string a,int b){
    string result = "";
    int carry = 0;
    for(int i=a.length()-1;i>=0;i--){
        int product = (a[i] - '0') * b + carry;
        result.push_back(product%10 + '0');
        carry = product/10;
    }
    while(carry){
        result.push_back(carry%10 + '0');
        carry = carry/10;
    }
    reverse(result.begin(),result.end());
    return result;
}

string bigFactorial(int n){
    string result = "1";
    for(int i=2;i<=n;i++){
        result = multiply(result,i);
    }
    return result;
}




int main(){
    cout<<bigFactorial(100);
    return 0;
}