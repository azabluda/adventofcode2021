#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

string input();

int main() {
    string line;
    deque<string> A;
    for (stringstream file(input()); getline(file, line);)
        A.push_back(line);
    size_t res1 = 0, res2 = 0, m = size(A), n = size(A[0]);
    for (int step = 1; step <= 100 || !res2; ++step) {
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (A[r][c] < '9') ++A[r][c];
                else q.push({ r, c });
        while (size(q)) {
            auto [r, c] = q.front();
            q.pop();
            if (r < 0 || r == m || c < 0 || c == n) continue;
            if (A[r][c] > '9') continue;
            if (A[r][c]++ < '9') continue;
            if (step <= 100) ++res1;
            for (int i = -1; i <= 1; ++i)
                for (int j = -1; j <= 1; ++j)
                    q.push({ r + i, c + j });
        }
        auto noflash = m * n;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (A[r][c] > '9') {
                    A[r][c] = '0';
                    --noflash;
                }
        if (!res2 && !noflash)
            res2 = step;
    }
    cout << "Part 1: " << res1 << endl;
    cout << "Part 2: " << res2 << endl;
}

string input1() {
    return R"(5483143223
2745854711
5264556173
6141336146
6357385478
4167524645
2176841721
6882881134
4846848554
5283751526
)";
}

string input() {
    return R"(8826876714
3127787238
8182852861
4655371483
3864551365
1878253581
8317422437
1517254266
2621124761
3473331514
)";
}