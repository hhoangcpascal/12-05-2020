/// DTTQ 08102007 <3
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <time.h>
#define llong long long

using namespace std;

typedef struct KD_Tree {
    llong x[2];
    KD_Tree *_left, *_right;
} *Node;

inline llong dist(Node a, Node b, int dim) {
    llong t, d = 0;
    while (dim--) {
        t = a->x[dim] - b->x[dim];
        d += t*t;
    }
    return d;
}

inline void _swap(Node x, Node y) {
    swap(x->x[0], y->x[0]);
    swap(x->x[1], y->x[1]);
}

Node find_median(Node _start, Node _end, int idx) {
    if (_end <= _start) return NULL;
    if (_end == _start + 1) return _start;
    Node p, store, mid = _start + (_end - _start) / 2;
    llong pivot;
    while (true) {
        pivot = mid->x[idx];
        _swap(mid, _end-1);
        for(store = p = _start; p < _end; ++p)
        if (p->x[idx] < pivot) {
            if (p != store) _swap(p, store);
            ++store;
        }
        _swap(store, _end-1);
        if (store->x[idx] == mid->x[idx]) return mid;
        if (store > mid) _end = store; else _start = store;
    }
}

Node make_tree(Node t, int len, int i, int dim) {
    Node n;
    if (len == 0) return NULL;
    if ((n = find_median(t, t+len, i))) {
        i = (i+1) % dim;
        n->_left = make_tree(t, n-t, i, dim);
        n->_right = make_tree(n+1, t + len - (n + 1), i, dim);
    }
    return n;
}

void nearest(Node root, Node test, int i, int dim, llong *best_dist) {
    llong d, dx, dx2;
    if (!root) return;
    d = dist(root, test, dim);
    dx = root->x[i] - test->x[i];
    dx2 = dx*dx;
    if (d < *best_dist) {
        *best_dist = d;
    }
    i = (i+1) % dim;
    nearest(dx > 0 ? root->_left : root->_right, test, i, dim, best_dist);
    if (dx2 >= *best_dist) return;
    nearest(dx > 0 ? root->_right : root->_left, test, i, dim, best_dist);
}

int n, m;
llong r;
KD_Tree P[1006], Q[1000006];

template<typename T>
bool fast_scan(T &num) {
    num = 0;
    register char c = getchar();
    while (c != '-' && (c < '0' || '9' < c)) {
        if (feof(stdin)) return false;
        c = getchar();
    }
    bool neg = false;
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; '0' <= c && c <= '9'; c = getchar()) num = (num << 1) + (num << 3) + (c - '0');
    if (neg) num = -num;
    return true;
}

int randInt(int l, int r) {
    int _rand = rand() * rand();
    _rand *= (rand() % 2 + 1);
    return l + _rand % (r-l+1);
}

void test_case() {
    set<pair<int, int> > S;
    freopen("SPID.inp", "w", stdout);
    cout << 1000 << " " << 1000000 << " " <<  randInt(30000, 50000) << "\n";
    for(int i=1; i<=1000; ++i) {
        int x = randInt(-60000, 60000);
        int y = randInt(-60000, 60000);
        while (S.count(make_pair(x, y))) x = randInt(-60000, 60000), y = randInt(-60000, 60000);
        S.insert(make_pair(x, y)); cout << x << " " << y << "\n";
    }
    S.clear();
    for(int i=1; i<=1000000; ++i) {
        int x = randInt(40000, 100000);
        int y = randInt(40000, 100000);
        if (rand() % 2) x = -x;
        if (rand() % 2) y = -y;
        while (S.count(make_pair(x, y))) {
            x = randInt(40000, 100000), y = randInt(40000, 100000);
            if (rand() % 2) x = -x;
            if (rand() % 2) y = -y;
        }
        S.insert(make_pair(x, y)); cout << x << " " << y << "\n";
    }
}

int main() {
    srand(time(NULL));
    //test_case();
    freopen("SPID.inp", "r", stdin);
    freopen("SPID.out", "w", stdout);
    fast_scan(n); fast_scan(m); fast_scan(r);
    for(int i=0; i<n; ++i) {
        fast_scan(P[i].x[0]);
        fast_scan(P[i].x[1]);
    }
    for(int i=0; i<m; ++i) {
        fast_scan(Q[i].x[0]);
        fast_scan(Q[i].x[1]);
    }
    Node root = make_tree(Q, m, 0, 2);
    int res = 0;
    for(int i=0; i<n; ++i) {
        llong best_dist = 1e18;
        nearest(root, &P[i], 0, 2, &best_dist);
        if (best_dist <= r*r) ++res;
    }
    cout << res;
    return 0;
}
