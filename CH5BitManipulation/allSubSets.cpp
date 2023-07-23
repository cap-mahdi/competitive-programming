#include <bits/stdc++.h>

using namespace std;

void subset(string ch){
    int n = ch.size();
    int range = (1 << n) - 1;
    for(int i=0; i<=range;i++){
        int temp = i;
        int j=0;
        while(temp){
            if(temp & 1){
                cout << ch[j];
            }
            j++;
            temp = temp >> 1;
        }
        cout << endl;
    }
    
}



int main(){
    string ch;
    cin >> ch;
    subset(ch);
    return 0;
}