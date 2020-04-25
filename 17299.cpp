#include<iostream>
#include<vector>
#include<stack>

std::vector<int> v;
std::vector<int> freq;
std::vector<int> ans;
std::stack<int> s;

int main(void) {
    int n;
    std::cin >> n;
    v = std::vector<int>(n, 0);
    freq = std::vector<int>(1000001, 0);
    ans = std::vector<int>(n, 0);

    for(int i = 0; i < n; ++i) {
        std::cin >> v[i];
        ++freq[v[i]];
    }

    for(int i = 0; i < n; ++i) {
        while(!s.empty() && freq[v[s.top()]] < freq[v[i]]) {
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()) {
        ans[s.top()] = -1; 
        s.pop();    
    }
    
    for(const auto& elem : ans)
        std::cout << elem << " ";
}