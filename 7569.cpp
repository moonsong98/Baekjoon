#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include<algorithm> 

int M, N, H;

int arr[100][100][100];
int dir[6][3] = { {-1, 0, 0},
                  {1, 0, 0}, 
                  {0, -1, 0},
                  {0, 1, 0},
                  {0, 0, -1},
                  {0, 0, 1}};
std::queue<std::tuple<int, int, int, int>> q;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> M >> N >> H;
    int leftTomato = 0;
    int maxDay = 0;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                std::cin >> arr[k][j][i];
                switch (arr[k][j][i])
                {
                case 1:
                    q.push({k, j, i, 0});
                    break;
                case 0:
                    ++leftTomato;
                    break;
                }
            }
        }
    }
    while (!q.empty() && leftTomato)
    {
        auto cur = q.front();
        q.pop();
        int x = std::get<0>(cur);
        int y = std::get<1>(cur);
        int z = std::get<2>(cur);
        int day = std::get<3>(cur) + 1;
        for (int k = 0; k < 6; k++)
        {
            int nextx = x + dir[k][0], nexty = y + dir[k][1], nextz = z + dir[k][2];
            if(nextx < 0 || nextx >= M || nexty < 0 || nexty >= N || nextz < 0 || nextz >= H || arr[nextx][nexty][nextz]) continue;
            arr[nextx][nexty][nextz] = 1;
            q.push({nextx, nexty, nextz, day});
            maxDay = std::max(maxDay, day);
            --leftTomato;
        }
    }

    if (leftTomato)
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << maxDay << '\n';
    }
}