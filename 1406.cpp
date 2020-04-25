#include<iostream>
#include<list>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string str;
    std::list<char> lc;
    int n;
    std::cin >> str;
    lc = std::list<char>(str.begin(), str.end());
    std::cin >> n;
    std::list<char>::iterator it = lc.end();


    for(int i = 0; i < n; ++i) {
        char c;
        std::cin >> c;
        switch (c) {
        case 'L':
            if(it != lc.begin())
                --it;
            break;
        case 'D':
            if(it != lc.end())
                ++it;
            break;
        case 'B':
            if(it != lc.begin()) {
                --it;
                it = lc.erase(it);
            }
            break;
        case 'P':
            char ch;
            std::cin >> ch;
            it = lc.insert(it, ch);
            ++it;

            break;
        }
    }
    for (const auto &ch : lc)
        std::cout << ch;
    std::cout << '\n';
}