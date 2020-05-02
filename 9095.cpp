#include<iostream>

using namespace std;

int dp[11];
int DP(int n) {
    if(n == 1) return dp[1] = 1;
    if(n == 2) return dp[2] = 2;
    if(n == 3) return dp[3] = 4;
    return dp[n] = DP(n-3) + DP(n-2) + DP(n-1);
}

int main(void) {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << DP(n) << '\n';
    }
    
}