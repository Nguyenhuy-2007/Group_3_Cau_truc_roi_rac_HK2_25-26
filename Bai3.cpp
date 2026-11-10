#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

typedef pair<int,int> pii;
const int INF = INT_MAX;

int n, m;
vector<pii> graph[101];

void addEdge(int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

void dijkstra(int s, int t) {
    vector<int> dist(n+1, INF);
    vector<int> prev(n+1, -1);
    vector<bool> visited(n+1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v, w] : graph[u]) {
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // --- Ket qua duong di tu s den t ---
    cout << "\n--- KET QUA DUONG DI TU " << s << " DEN " << t << " ---\n";
    if (dist[t] == INF) {
        cout << "Khong co duong di tu " << s << " den " << t << "\n";
    } else {
        vector<int> path;
        for (int cur = t; cur != -1; cur = prev[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());

        cout << "Duong di ngan nhat: ";
        for (int i = 0; i < (int)path.size(); i++) {
            if (i) cout << " -> ";
            cout << path[i];
        }
        cout << "\nTong trong so: " << dist[t] << "\n";
    }

    // --- Bang trong so tu dinh s den tat ca dinh ---
    int c0 = 10, c1 = 14, c2 = 22;
    string hl  = "+" + string(c0,'-') + "+" + string(c1,'-') + "+" + string(c2,'-') + "+";
    string hl2 = "+" + string(c0,'=') + "+" + string(c1,'=') + "+" + string(c2,'=') + "+";

    cout << "\n--- TRONG SO TU DINH " << s << " DEN CAC DINH KHAC ---\n";
    cout << hl << "\n";
    cout << "| " << left << setw(c0-1) << "Dinh dich"
         << "| " << left << setw(c1-1) << "Trong so NNN"
         << "| " << left << setw(c2-1) << "Duong di" << "|\n";
    cout << hl2 << "\n";

    for (int v = 1; v <= n; v++) {
        if (v == s) continue;

        string distStr = (dist[v] == INF) ? "INF" : to_string(dist[v]);

        string pathStr = "";
        if (dist[v] != INF) {
            vector<int> path;
            for (int cur = v; cur != -1; cur = prev[cur])
                path.push_back(cur);
            reverse(path.begin(), path.end());
            for (int i = 0; i < (int)path.size(); i++) {
                if (i) pathStr += " -> ";
                pathStr += to_string(path[i]);
            }
        } else {
            pathStr = "Khong co duong di";
        }

        cout << "| " << left << setw(c0-1) << v
             << "| " << left << setw(c1-1) << distStr
             << "| " << left << setw(c2-1) << pathStr << "|\n";
        cout << hl << "\n";
    }
}

int main() {
    cout << "=== THUAT TOAN DIJKSTRA - DON DO THI VO HUONG ===\n\n";

    cout << "Nhap so dinh n va so canh m: ";
    cin >> n >> m;

    cout << "Nhap " << m << " canh (dinh u, dinh v, trong so w):\n";
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cout << "  Canh " << i << ": ";
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    // In danh sach ke dang bang
    int colWidth = 10;
    for (int u = 1; u <= n; u++) {
        int len = 0;
        for (auto [v, w] : graph[u])
            len += to_string(v).size() + 1 + to_string(w).size() + 2 + 2;
        if (len > colWidth) colWidth = len;
    }
    colWidth += 2;

    int col1 = 6;
    string hline1 = "+" + string(col1, '-') + "+" + string(colWidth, '-') + "+";
    string hline2 = "+" + string(col1, '=') + "+" + string(colWidth, '=') + "+";

    cout<<"\n=== DANH SACH KE ===\n";
    cout << "\n" << hline1 << "\n";
    cout << "| " << left << setw(col1-1) << "u"
         << "| " << left << setw(colWidth-1) << "Ke(u)" << "|\n";
    cout << hline2 << "\n";

    for (int u = 1; u <= n; u++) {
        string ke = "";
        for (auto [v, w] : graph[u])
            ke += to_string(v) + "(" + to_string(w) + ")  ";

        cout << "| " << left << setw(col1-1) << u
             << "| " << left << setw(colWidth-1) << ke << "|\n";

        if (u < n)
            cout << hline1 << "\n";
    }
    cout << hline1 << "\n";

    int s, t;
    cout << "\nNhap dinh nguon s va dinh dich t: ";
    cin >> s >> t;

    dijkstra(s, t);

    return 0;
}