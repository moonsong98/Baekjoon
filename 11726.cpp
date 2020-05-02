#include<iostream>

using namespace std;

int dp[1001] = {0, };
int DP(int n) {
    if(dp[n]) return dp[n];
    if(n == 1) return 1;
    if(n == 2) return 2;
    return dp[n] = (DP(n-1) + DP(n-2)) % 10007; 
}

int main(void) {
    int n;
    cin >> n;
    cout << DP(n) << '\n';
}