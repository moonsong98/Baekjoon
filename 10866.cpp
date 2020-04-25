#include<iostream>
#include<stack>
#include<string>

std::string cmd[8] {
    "push_front", "push_back", "pop_front", "pop_back", "size", "empty", "front", "back"
};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::stack<int> front, back;
    std::cin >> n;

    while(n--) {
        std::string str;
        std::cin >> str;

        for(int i = 0; i < 8; ++i) {
            if(str.compare(cmd[i])) continue;
            int input;
            switch(i) {
                case 0:
                    std::cin >> input;
                    front.push(input);
                    break;
                case 1:
                    std::cin >> input;
                    back.push(input);
                    break;
                case 2:
                    if(!front.size()) {
                        if(!back.size()) {
                            std::cout << -1 << '\n';
                            break;
                        }
                        while(back.size() > 1) {
                            front.push(back.top());
                            back.pop();
                        }
                        std::cout << back.top() << '\n';
                        back.pop();
                    } else {
                        std::cout << front.top() << '\n';
                        front.pop();
                    }
                    break;
                case 3:
                    if (!back.size()) {
                        if (!front.size()) {
                            std::cout << -1 << '\n';
                            break;
                        }
                        while (front.size() > 1) {
                            back.push(front.top());
                            front.pop();
                        }
                        std::cout << front.top() << '\n';
                        front.pop();
                    } else {
                        std::cout << back.top() << '\n';
                        back.pop();
                    }
                    break;
                case 4:
                    std::cout << front.size() + back.size() << '\n';
                    break;
                case 5:
                    if(front.size() == 0 and back.size() == 0) {
                        std::cout << 1 << '\n';
                    } else {
                        std::cout << 0 << '\n';
                    }
                    break;
                case 6:
                    if (!front.size()) {
                        if (!back.size()) {
                            std::cout << -1 << '\n';
                            break;
                        }
                        while (back.size() > 0) {
                            front.push(back.top());
                            back.pop();
                        }
                        std::cout << front.top() << '\n';
                    } else {
                        std::cout << front.top() << '\n';
                    }
                    break;
                case 7:
                    if (!back.size()) {
                        if (!front.size()) {
                            std::cout << -1 << '\n';
                            break;
                        }
                        while (front.size() > 0) {
                            back.push(front.top());
                            front.pop();
                        }
                        std::cout << back.top() << '\n';
                    } else {
                        std::cout << back.top() << '\n';
                    }
                    break;
            }
        }
    }
}