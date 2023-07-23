#include <bits/stdc++.h>

using namespace std;

void swap(string &a,string &b){
    string temp = a;
    a = b;
    b = temp;
}

string addBigIntegers(string a,string b){
    if(a.length() > b.length())
        swap(a,b);
    
    string result = "";

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int carry = 0;
    for(int i = 0; i<a.length();i++){
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result.push_back(sum%10 + '0');
        carry = sum/10;
    }

    for(int i = a.length();i<b.length();i++){
        int sum = (b[i] - '0') + carry;
        result.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if(carry)
        result.push_back('1');
    
    reverse(result.begin(),result.end());

    return result;
}


int main(){
    string a,b;
    cin>>a>>b;
    string result = addBigIntegers(a,b);
    cout<<result;
    return 0;
}