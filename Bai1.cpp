#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "=== TIM BAC CUA DINH ===\n\n";
    cout << "Nhap so dinh cua do thi: ";
    if (!(cin >> n) || n <= 0) {
        cout << "So dinh khong hop le!" << endl;
        return 1;
    }

    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
    vector<int> degree(n + 1, 0);
    int w = 5; 

    cout << "\n--- NHAP MA TRAN KE (theo tung hang) ---" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Hang " << i << ": ";
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                degree[i]++;
            }
        }
    }

    cout << "\n MA TRAN KE DA NHAP:" << endl;
    cout << setw(w) << " " << "|";
    for (int j = 1; j <= n; j++) cout << setw(w) << j << "|";
    cout << endl;

    string separator = string(w, '-') + "+" + string(n * (w + 1), '-');
    cout << separator << endl;

    for (int i = 1; i <= n; i++) {
        cout << setw(w) << i << "|"; 
        for (int j = 1; j <= n; j++) {
            cout << setw(w) << matrix[i][j] << "|";
        }
        cout << endl << separator << endl;
    }

    cout << "\n DAY BAC CUA CAC DINH:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "deg(" << i << ") = " << degree[i] << endl;
    }

    return 0;
}