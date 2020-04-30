#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

struct lec {
    int s, e;
} lec[200000];

priority_queue <int, vector<int>, greater<int>> endTime;

void solve() {
    int roomNum;
    std::cin >> roomNum;
    for(int i = 0; i < roomNum; ++i) {
        std::cin >> lec[i].s >> lec[i].e;
    }
    auto comp = [] (const struct lec& e1, const struct lec& e2) {
        return e1.s < e2.s;
    }; // true: e1 goes before e2
    sort(lec, lec + roomNum, comp);
    
    for(int i = 0; i < roomNum; ++i) {
        if(endTime.empty() || endTime.top() > lec[i].s) {
            endTime.push(lec[i].e);
        } else {
            endTime.pop();
            endTime.push(lec[i].e);
        }
    }
    cout << endTime.size();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}