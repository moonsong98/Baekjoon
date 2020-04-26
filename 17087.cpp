#include<iostream>
#include<queue>
#include<vector>

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    int n, s;
    std::priority_queue<int> pq;
    std::vector<int> diff;
    std::cin >> n >> s;
    pq.push(s);
    for(int i = 0; i < n; ++i) {
        int input;
        std::cin >> input;
        pq.push(input);
    }
    int a = pq.top();
    pq.pop();
    while(!pq.empty()) {
        int b = pq.top();
        pq.pop();
        diff.push_back(a - b);
        a = b;
    }
    int ans = gcd(diff[0], diff[1]);
    for(int i = 2; i < diff.size(); ++i) {
        ans = gcd(ans, diff[i]);
    }
    std::cout << ans << '\n';
}