#include<iostream>

int five(int n) {
    int sum = 0;
    while(!(n % 5)) {
        ++sum;
        n/=5;
    }
    return sum;
}

int main(void) {
    int n;
    int sum = 0;
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
        sum += i % 5 ? 0 : five(i);
    std::cout << sum << '\n';
}