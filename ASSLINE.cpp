/// DTTQ 08102007 <3
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int P[2][36], n[3];
int time_a, time_b;

void init() {
    int sum;
    do {
        ++time_a; sum = 0;
        for(int i=1; i<=n[0]; ++i)
            sum += time_a / P[0][i];
    } while (sum < n[2]);
    do {
        ++time_b; sum = 0;
        for(int i=1; i<=n[1]; ++i)
            sum += time_b / P[1][i];
    } while (sum < n[2]);
    cout << time_a << "\n";
}

int finish(int block, int t) {
    int sum = 0;
    for(int i=1; i<=n[block]; ++i)
        if (t % P[block][i] == 0) ++sum;
    int up_to = 0;
    for(int i=1; i<=n[block]; ++i) up_to += (t-1) / P[block][i];
    if (up_to >= n[2]) sum = 0;
    else if (up_to + sum >= n[2]) sum = n[2] - up_to;
    return sum;
}

void adjust() {
    int d = 1, t = 0, inter = 0;
    while (d + t < time_a) {
        inter += finish(0, d+t);
        int job_b = finish(1, time_b - t);
        while (inter < job_b) {
            ++d;
            inter += finish(0, d+t);
        }
        inter -= job_b;
        ++t;
    }
    cout << time_b + d;
}

int main() {
    freopen("ASSLINE.inp", "r", stdin);
    freopen("ASSLINE.out", "w", stdout);
    scanf("%d%d", &n[2], &n[0]);
    for(int i=1; i<=n[0]; ++i) scanf("%d", &P[0][i]);
    scanf("%d", &n[1]);
    for(int i=1; i<=n[1]; ++i) scanf("%d", &P[1][i]);
    init();
    adjust();
    return 0;
}
