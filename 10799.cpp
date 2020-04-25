#include<iostream>
#include<string>
#include<stack>

int main (void) {
    std::string str;
    std::stack<char> s;
    std::cin >> str;
    int ans = 0;
    s.push('(');
    for (int i = 1; i < str.size(); ++i) {
        char prev = str[i-1];
        char cur = str[i];
        if (prev == '(') {
            if (cur == '(') {
                s.push(cur);
            } else {
                s.pop();
                ans += s.size();
            }
        } else {
            if (cur == '(') {
                s.push(cur);
            } else {
                s.pop();
                ++ans;
            }
        }
    }
    std::cout << ans << '\n';
}