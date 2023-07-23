#include <bits/stdc++.h>
using namespace std;

int getIthBit(int n, int i){
return (n & (1 << i)) != 0;
}

void setIthBit(int &n, int i){
n = n | (1 << i);
}

void clearIthBit(int &n, int i){
n = n & (~(1 << i));
}

void updateIthBit(int &n, int i, int v){
clearIthBit(n, i);
n = n | (v << i);
}

void clearLastIBits(int &n, int i){
int mask = (-1 << i);
n=  n & mask;
}

void clearRangeItoJ(int &n, int i, int j){
int a = (-1 << (j + 1));
int b = (1 << i) - 1;
int mask = a | b;
n = n & mask;
}

void replaceBits(int &n, int m, int i, int j){
//replacee i to j bits of n with m
clearRangeItoJ(n, i, j);
n = n | (m << i);
}
int checkPowerOf2(int n){ 
return (n & (n - 1)) == 0;
}
int countSetBits(int n){
//complexity: O(no. of set bits)
int count = 0;
while(n){
//remove last set bit
n = n & (n - 1);
count++;
}
return count;

//     //complexity: O(logn + 1) 
// int count = 0;
// while(n){
//     count += (n & 1);
//     n = n >> 1;
// }
// return count;
}

long long convertToBinary(int n){
long long ans = 0;
long long p = 1;
while(n){
ans += (n & 1) * p;
p *= 10;
n = n >> 1;
}
return ans;
}


int main(){
    return 0;
}