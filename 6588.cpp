#include<iostream>
#include<vector>

std::vector<bool> prime(10000001, true);
std::vector<int> primeNum;
void getPrime();

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    getPrime();
    
    while(true) {
        int n;
        int flag = false;
        int a, b;
        std::cin >> n;
        if(!n) return 0;
        for(int i = 0; i < primeNum.size(); ++i) {
            if(prime[n-primeNum[i]]) {
                a = primeNum[i];
                b = n - primeNum[i];
                break;
            }
        }
        std::cout << n << " = " << a << " + " << b << '\n';
    }
}

void getPrime() {
    prime[2] = true;
    for(int i = 2; i <= 1000; ++i) {
        if(!prime[i]) continue;
        if(i%2) primeNum.push_back(i);
        for(int j = i * i; j <= 1000000; ++j) {
            if(j % i == 0) prime[j] = false;
        }
    }
}