#include<iostream>
#include<vector>

int gcd (int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        long long sum = 0;
        std::vector<int> v;
        std::cin >> n;
        for(int i = 0; i < n; ++i) {
            int input;
            std::cin>>input;
            v.push_back(input);
        }
        int size = v.size();
        for(int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                sum += gcd(v[i], v[j]);
            }
        }
        std::cout << sum << '\n';
    }
}