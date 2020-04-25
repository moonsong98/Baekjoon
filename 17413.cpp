#include<iostream>
#include<stack>
#include<string>

int main(void) {
    std::string str;
    std::stack<char> s;
    std::getline(std::cin, str);
    for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
        if(*it == '<') {
            while(!s.empty()) {
                std::cout << s.top();
                s.pop();
            }
            while(*it != '>') {
                std::cout << *it;
                ++it;
            }
            std::cout << '>';
        } else {
            if(*it == ' ') {
                while (!s.empty()) {
                    std::cout << s.top();
                    s.pop();
                }
                std::cout << ' ';
            } else {
                s.push(*it);
            }
        }
    }
    while(!s.empty()) {
        std::cout << s.top();
        s.pop();
    }
    std::cout << '\n';
}