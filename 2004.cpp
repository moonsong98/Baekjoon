#include<iostream>
#define ll long long

ll numk(ll n, ll k) {
    ll sum = 0;
    ll d = k;
    while (d <= n) {
        sum += n / d;
        d *= k;
    }
    return sum;
}

int main (void) {
    ll n, m;
    ll cnt2 = 0;
    ll cnt5 = 0;
    std::cin >> n >> m;

    cnt5 = numk(n, 5) - numk(m, 5) - numk(n - m, 5);
    cnt2 = numk(n, 2) - numk(m, 2) - numk(n - m, 2);

    if(cnt5 >= cnt2) {
        std::cout << cnt2 << std::endl;
    } else {
        std::cout << cnt5 << std::endl;
    }
}