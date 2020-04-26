#include<iostream>
#include<string>
#include<stack>
int main(void) {
    std::string str;
    std::stack<int> s;
    std::cin >> str;
    int r = str.size() - 1;
    int l = (int)str.size() - 3 > 0 ? (int)str.size() - 3 : 0;
    while(true) {
        int m = 1;
        int sum = 0;
        for(int i = r; i >= l; --i) {
            if(str[i] == '1')
                sum += m;
            m *= 2;
        }
        s.push(sum);
        if(!l) break;
        r = l - 1;
        l = l - 3 > 0 ? l - 3 : 0;
    }
    while(!s.empty()) {
        std::cout << s.top();
        s.pop();
    }
}