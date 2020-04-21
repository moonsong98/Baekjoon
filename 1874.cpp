#include<iostream>
#include<stack>
#include<vector>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int pushNum = 1;
    int input;
    bool flag = true;
    std::stack<int> s;
    std::vector<char> vec;
    for(int i = 0; i < n; ++i) {
        std::cin >> input;        
        while(input >= pushNum) {
            s.push(pushNum++);
            vec.push_back('+');
        }
        if(s.top() == input) {
            s.pop();
            vec.push_back('-');
        } else {
            flag = false;
            break;
        }
    }
    if(flag)
        for(int i = 0; i < vec.size(); ++i)
            std::cout << vec[i] << '\n';
    else 
        std::cout << "NO" << '\n';
}