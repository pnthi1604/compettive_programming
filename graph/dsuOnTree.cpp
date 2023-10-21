int nmax = (int)2e5 + 1;
vector<vector<int>> adj[nmax];
vector<int> sz[nmax];//sz[u]: so dinh thuoc cay con goc u
bool big[nmax];

void add(int u, int p, int del) {
    //lam cai gi do
    for(int v : adj[u])
        if(big[v] == false)
            add(v, u, del);
}

void dsuOnTree(int u, int p, int keep) {
    int bigC = -1;
    for(int v : adj[u])
        if(v != p && (bigC == -1 || sz[bigC] < sz[v]))
            bigC = v;
    for(int v : adj[u])
        if(v != p && v != bigC)
            dsuOnTree(v, u, 0);
    if(bigC != -1) {
        big[bigC] = true;
        dsuOnTree(bigC, u, 1);
    }
    add(u, p, 1);
    if(bigC != -1)
        big[bigC] = false;
    if(keep == 0)
        add(u, p, -1);
}