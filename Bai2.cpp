#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

void DFS(int u, int n, const vector<vector<int>>& A, vector<bool>& visited) {
    cout << u << " ";       
    visited[u] = true;      

    for (int v = 1; v <= n; ++v) {
        if (A[u][v] == 1 && !visited[v]) {
            DFS(v, n, A, visited); 
        }
    }
}

int main() {
    int n;
    cout << "=== THUAT TOAN DFS ===\n\n";
    cout << "Nhap so luong dinh cua do thi: ";
    cin >> n;

    vector<vector<int>> A(n + 1, vector<int>(n + 1));
    int w = 5; 

    cout << "\n--- NHAP MA TRAN KE ---" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Hang " << i << ":";
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "\n MA TRAN KE DA NHAP:" << endl;
    
    cout << setw(w) << " " << "|";
    for (int j = 1; j <= n; j++) cout << setw(w) << j << "|";
    cout << endl;

    string line = string(w, '-') + "+" + string(n * (w + 1), '-');
    cout << line << endl;

    for (int i = 1; i <= n; i++) {
        cout << setw(w) << i << "|"; 
        for (int j = 1; j <= n; j++) {
            cout << setw(w) << A[i][j] << "|";
        }
        cout << endl << line << endl;
    }

    int start_vertex;
    cout << "\nNhap dinh bat dau duyet: ";
    cin >> start_vertex;

    if (start_vertex < 1 || start_vertex > n) {
        cout << "Dinh khong hop le!" << endl;
        return 0;
    }

    vector<bool> visited(n + 1, false);

    cout << "Thu tu duyet DFS tu dinh " << start_vertex << " la: ";
    DFS(start_vertex, n, A, visited);
    cout << endl;

    return 0;
}