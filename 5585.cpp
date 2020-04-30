#include<iostream>

using namespace std;

int coin[] = {500, 100, 50, 10, 5, 1};

int main(void) {
    int n;
    std::cin >> n;
    n = 1000 - n;
    int ans = 0;

    for(int i = 0; i < 6; ++i) {
        if(n >= coin[i]) {
            ans += n / coin[i];
            n %= coin[i];
        }
    }

    std::cout << ans << '\n';
}