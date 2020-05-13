/// DTTQ 08102007 <3
#include <iostream>
#include <algorithm>
#define llong long long

using namespace std;

int n, h[100006];
llong f[100006];

int main() {
    freopen("GSASUKE.inp", "r", stdin);
    freopen("GSASUKE.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &h[i]);
        f[i] = f[i-1] + abs(h[i] - h[i-1]);
        if (i >= 3) f[i] = min(f[i], f[i-2] + 2LL * abs(h[i] - h[i-2]));
    }
    cout << f[n];
    return 0;
}
