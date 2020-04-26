#include<iostream>

int main (void) {
    int a, b;
    std::cin >> a >> b;
    int gcd, lcm = a * b;

    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    gcd = a;
    lcm /= a;

    std::cout << gcd << '\n' << lcm << '\n';
}