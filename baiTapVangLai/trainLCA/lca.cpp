#include <bits/stdc++.h>
#define ll long long
#define hi cerr << "HIHIHI\n";
#define endl '\n'

using namespace std;

const int N = (int)2e5, K = log2(N) + 2;
vector<int> adj[N];
int p[N][K + 1];
int n, q;
bool vis[N];
int d[N];

void bfs() {
    queue<int> q;
    q.push(0);
    vis[0] = true;
    d[0] = 1;
    p[0][0] = 0;
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(vis[v] == false) {
                d[v] = d[u] + 1;
                p[v][0] = u;
                for(int i = 1; i < K; i++) {
                    p[v][i] = p[p[v][i - 1]][i - 1];
                }
                q.push(v);
                vis[v] = true;
            }
        }
    }
}

int lca(int u, int v) {
    

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    return 0;
}