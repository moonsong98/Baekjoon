#include<iostream>
#include<vector>
#include<stack>

int main (void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> v(n, 0);
    std::vector<int> ans(n, 0);
    std::stack<int> s;

    for(int i = 0; i < n; ++i)
        std::cin >> v[i];

    s.push(v[n-1]);
    ans[n-1] = -1;

    for(int i = n-2; i >= 0; --i) {
        if(v[i] < v[i+1]) {
            ans[i] = v[i+1];
            s.push(v[i]);
        } else if(v[i] == v[i+1]) {
            ans[i] = ans[i+1];
        } else {
            while(!s.empty() && s.top() <= v[i])
                s.pop();
            if(s.empty()) ans[i] = -1;
            else ans[i] = s.top();
            s.push(v[i]);
        }
    }

    for(const auto& elem : ans)
        std::cout << elem << " ";
}