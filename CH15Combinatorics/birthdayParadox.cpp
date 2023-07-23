#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    problem statement:- for t test cases, given p, find the minimum number of people to have the chance of two people having same birthday greater than p
    approach:- we will use the concept of probability to solve this problem.
    let's say we have n people in a room, then the probability of two people having same birthday is 1 - (365/365)*(364/365)*(363/365)*...*(365-n+1/365)
    we will keep on increasing n until the probability is greater than p/100.
    we assume that the distribution of birthdays is uniform.
    time complexity:- O(365)
    space complexity:- O(1)
*/
int minimum_number_of_people_to_have_the_chance_of_two_people_having_same_bday_greater_than_p(float p){
    int n = 0;
    double prob = 1.0;
    if(p == 100) return 366;
    while(prob > 1.0 - p/100.0 && n < 366){
        prob *= (365.0 - n)/365.0;
        n++;
    }
    return n;
}

void solve(){
    float p;
    cin>>p;
    cout<<minimum_number_of_people_to_have_the_chance_of_two_people_having_same_bday_greater_than_p(p)<<endl;
}
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