/******************************************************************************

Nguyen Duong Tung
V202000270
VinUniversity

*******************************************************************************/
	
#include<cstdio>
#include<climits>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
 
#define INF 1000000000
#define N 500
#define REP(i, n) for(int i = 0; i < (n); ++i)
typedef pair<int, int> ii;
int favor[N], a[N][N], n, f, c;
vector<vector<ii> > g;
 
void enter() {
    scanf("%d%d%d",&n,&f,&c);
    for(int i = 0; i < f; favor[i++]--) scanf("%d", favor+i);
    g.resize(n);
    for(int u, v, l, i = 0; i < c; ++i) {
        scanf("%d%d%d",&u,&v,&l);
        g[--u].push_back(ii(--v,l)); g[v].push_back(ii(u,l));
    }
}
 
void dijkstra(int s, int d[]) {
    REP(u, n) d[u] = INF; d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > q; q.push(ii(0, s));
    while(!q.empty()) {
        int u = q.top().second, du = q.top().first; q.pop();
        if(du > d[u]) continue;
        for(vector<ii>::iterator it = g[u].begin(); it != g[u].end(); ++it) {
            int v = it->first, l = it->second;
            if(du + l < d[v]) q.push(ii(d[v] = du + l, v));
        }
    }
}
 
void solve() {
    REP(u, n) dijkstra(u, a[u]);
    int mn = INT_MAX, pos = 0;
    REP(i,n) {
        int total = 0;
        for(int j=0; j < f; total += a[i][favor[j++]]);
        if(total < mn) mn = total, pos = i;
    }
    printf("%d\n", pos+1);
}
 
int main() {
    enter();
    solve();
    return 0;
}
 
