/// DTTQ 08102007 <3
#include <iostream>
#include <algorithm>

using namespace std;

int f[306][36], dist[306][306];
int n, m, V[306];

void print_trace(int i, int j) {
    if (j > 1) {
        int pos = 0;
        for(int k=j-1; k<=i-1; ++k)
        if (f[k][j-1] + dist[k][i] == f[i][j]) {
            pos = k; break;
        }
        print_trace(pos, j-1);
    }
    if (i <= n) cout << V[i] << " ";
}

int main() {
    freopen("POST.inp", "r", stdin);
    freopen("POST.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &V[i]);
    V[0] = -1000000; V[n+1] = 1000000;
    for(int i=0; i<=n; ++i)
    for(int j=i+1; j<=n+1; ++j)
    for(int k=i; k<=j; ++k) dist[i][j] += min(V[k]-V[i], V[j] - V[k]);
    for(int i=1; i<=n; ++i) f[i][1] = dist[0][i];
    for(int j=2; j<=m+1; ++j)
    for(int i=j; i<=n+1; ++i) {
        f[i][j] = 1e9;
        for(int k=j-1; k<=i-1; ++k) f[i][j] = min(f[i][j], f[k][j-1] + dist[k][i]);
    }
    cout << f[n+1][m+1] << "\n";
    print_trace(n+1, m+1);
    return 0;
}
