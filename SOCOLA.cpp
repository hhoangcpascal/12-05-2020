/// DTTQ 08102007 <3
#include <iostream>
#include <algorithm>

using namespace std;

int m, n;

int main() {
    freopen("SOCOLA.inp", "r", stdin);
    freopen("SOCOLA.out", "w", stdout);
    cin >> m >> n;
    cout << m + n - __gcd(m, n);
    return 0;
}
