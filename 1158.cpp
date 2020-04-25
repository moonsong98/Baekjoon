#include<iostream>
#include<queue>

int main(void) {
    int n, k;
    std::queue<int> ans;
    std::queue<int> q;
    std::cin >> n >> k;

    for(int i = 1; i <= n; ++i)
        q.push(i);

    while(!q.empty()) {
        for(int i = 1; i < k; ++i) {
            int elem = q.front();
            q.pop();
            q.push(elem);
        }
        ans.push(q.front());
        q.pop();
    }

    std::cout << "<";
    while(!ans.empty()) {
        std::cout << ans.front();
        if(ans.size() > 1) std::cout << ", ";
        ans.pop();
    }
    std::cout << ">\n";
}