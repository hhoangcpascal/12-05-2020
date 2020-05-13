/// DTTQ 08102007 <3
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

llong C[32][32], m;
int n;

int main() {
    freopen("TAP_N.inp", "r", stdin);
    freopen("TAP_N.out", "w", stdout);
    for(int i=0; i<=31; ++i) {
        C[i][0] = 1;
        for(int j=1; j<=i; ++j) C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
    while (scanf("%d%I64d", &n, &m) != -1) {
        int pos = 0; llong sum = 0;
        for(int &i=pos; i<=n; ++i) {
            sum += C[n][i];
            if (sum >= m) {
                m -= sum - C[n][i]; break;
            }
        }
        int l = n; sum = 1;
        for(int i=1; i<=n; ++i)
        if (m <= C[l-1][pos-1]) sum = sum*3 + 1, --l, --pos; else sum = sum*2+1, m -= C[l-1][pos-1], --l;
        cout << sum << "\n";
    }
    return 0;
}
