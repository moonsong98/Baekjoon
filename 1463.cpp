#include<iostream>
#include<algorithm>
#define MAX 1000001

using namespace std;

int dp[1000001];

int DP(int n) {
    if (n == 1) return 0;
    if (dp[n] > -1) return dp[n];
    int minVal = MAX;
    if(!(n%3)) {
        minVal = min(minVal, DP(n/3)+1);
    } 
    if(!(n%2)) { 
        minVal = min(minVal, DP(n/2)+1);
    }
    return dp[n] = min(minVal, DP(n-1)+1);

}

int main(void) {
    int n;

    std::cin >> n;
    for(int i = 1; i <= n; ++i) dp[i] = -1;
    cout << DP(n) << '\n';
}