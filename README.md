# Bài tập lớn – Cấu trúc rời rạc (Nhóm 03)

Bộ chương trình C++ giải 3 bài toán đồ thị trên cùng một đơn đồ thị vô hướng có trọng số gồm **8 đỉnh, 14 cạnh**: tính bậc các đỉnh, duyệt DFS và tìm đường đi ngắn nhất bằng Dijkstra.

## Thông tin nhóm

- **Nhóm:** 03
- **Trưởng nhóm:** Nguyễn Võ Quang Huy

| TT | Họ tên | Công việc | Đóng góp |
|----|--------|-----------|----------|
| 1 | Lê Hoàng Huấn | Code bài 2 | 15% |
| 2 | Nguyễn Hoàng Gia Hưng | Code bài 3 | 15% |
| 3 | Trần Lê Phước Gia Hưng | Giải tay bài 2 | 15% |
| 4 | Đặng Lê Minh Huy | Giải tay bài 3 | 15% |
| 5 | Mai Quốc Huy | Code bài 1 | 15% |
| 6 | Nguyễn Võ Quang Huy | Hỗ trợ giải tay, làm file Word, kiểm tra, fix lỗi code | 25% |

## Cấu trúc thư mục

```
.
├── Bai1.cpp                 # Bài 1: ma trận kề + bậc của các đỉnh
├── Bai2.cpp                 # Bài 2: DFS trên ma trận kề
├── Bai3.cpp                 # Bài 3: Dijkstra trên danh sách kề
├── Bài_làm_-_Nhóm_3.docx    # Báo cáo (Word)
├── Bài_làm_-_Nhóm_3.pdf     # Báo cáo (PDF)
└── README.md
```

## Đồ thị mẫu

Đồ thị vô hướng, 8 đỉnh, 14 cạnh (định dạng `u v w`):

```
1 2 15     2 3 11     3 6 7      5 6 19
1 3 13     2 4 21     4 5 6      6 7 22
1 6 9      2 8 16     4 7 23
1 8 22     3 4 18
           3 5 15
```

## Yêu cầu & biên dịch

Cần trình biên dịch hỗ trợ **C++17** trở lên (Bài 3 dùng structured bindings).

```bash
g++ -std=c++17 -o Bai1 Bai1.cpp
g++ -std=c++17 -o Bai2 Bai2.cpp
g++ -std=c++17 -o Bai3 Bai3.cpp
```

Chạy:

```bash
./Bai1      # Linux/macOS
Bai1.exe    # Windows
```

---

## Bài 1 – Bậc của các đỉnh

**Đề bài:** Đọc đơn đồ thị vô hướng dạng ma trận kề, xuất dãy bậc của tất cả các đỉnh.

**Cách làm:**
- Lưu đồ thị bằng ma trận kề `vector<vector<int>>`, mảng bậc `vector<int> degree`.
- Khi nhập hàng `i`, mỗi phần tử `A[i][j] == 1` thì tăng `degree[i]` lên 1.
- In ma trận dạng bảng căn biên (`setw`) và danh sách bậc.

**Ví dụ nhập:**

```
8
0 1 1 0 0 1 0 1
1 0 1 1 0 0 0 1
1 1 0 1 1 1 0 0
0 1 1 0 1 0 1 0
0 0 1 1 0 1 0 0
1 0 1 0 1 0 1 0
0 0 0 1 0 1 0 0
1 1 0 0 0 0 0 0
```

**Kết quả:**

| Đỉnh | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|------|---|---|---|---|---|---|---|---|
| Bậc  | 4 | 4 | 5 | 4 | 3 | 4 | 2 | 2 |

**Độ phức tạp:** thời gian O(n²), bộ nhớ O(n²).

---

## Bài 2 – Duyệt DFS

**Đề bài:** Đọc đơn đồ thị vô hướng dạng ma trận kề, nhập đỉnh bắt đầu, xuất thứ tự duyệt DFS.

**Cách làm:**
- Hàm đệ quy `DFS(u, n, A, visited)`: in `u`, đánh dấu đã thăm, rồi lần lượt gọi đệ quy cho các đỉnh kề chưa thăm **theo thứ tự tăng dần**.
- Mảng `vector<bool> visited` tránh lặp vô hạn.
- Kiểm tra đỉnh bắt đầu có nằm trong `[1, n]` hay không.

**Ví dụ:** nhập ma trận kề như Bài 1.

| Đỉnh bắt đầu | Thứ tự duyệt DFS |
|--------------|------------------|
| 1 | 1 2 3 4 5 6 7 8 |
| 5 | 5 3 1 2 4 7 6 8 |

**Độ phức tạp:** thời gian O(n²) với ma trận kề.

**Hạn chế:** đệ quy có thể gây tràn ngăn xếp với đồ thị rất lớn; DFS không đảm bảo đường đi ngắn nhất.

---

## Bài 3 – Dijkstra

**Đề bài:** Đọc đơn đồ thị vô hướng dạng danh sách kề, nhập đỉnh nguồn `s` và đỉnh đích `t`, tìm đường đi ngắn nhất từ `s` đến `t`.

**Cách làm:**
- Danh sách kề `vector<pii> graph[101]` lưu cặp `(đỉnh kề, trọng số)`; hàm `addEdge` thêm cạnh hai chiều.
- `priority_queue` (min-heap) luôn lấy đỉnh có khoảng cách nhỏ nhất.
- Mảng `dist[]` (khoảng cách), `prev[]` (truy vết đường đi), `visited[]` (đỉnh đã tối ưu).
- Chương trình in danh sách kề, đường đi ngắn nhất `s → t` cùng tổng trọng số, và bảng đường đi ngắn nhất từ `s` đến mọi đỉnh.

**Định dạng nhập:**

```
n m
u v w      (lặp m lần)
s t
```

**Ví dụ:** nhập `8 14`, 14 cạnh như trên, rồi `1 8`.

```
Duong di ngan nhat: 1 -> 8
Tong trong so: 22
```

Bảng đường đi ngắn nhất từ đỉnh 1:

| Đỉnh đích | Trọng số | Đường đi |
|-----------|----------|----------|
| 2 | 15 | 1 → 2 |
| 3 | 13 | 1 → 3 |
| 4 | 31 | 1 → 3 → 4 |
| 5 | 28 | 1 → 6 → 5 |
| 6 | 9 | 1 → 6 |
| 7 | 31 | 1 → 6 → 7 |
| 8 | 22 | 1 → 8 |

**Độ phức tạp:** O((n + m) log n).

**Hạn chế:** chỉ đúng với trọng số không âm; mảng `graph[101]` giới hạn tối đa 100 đỉnh.

---

## Lưu ý

- Các đỉnh được đánh số từ **1** đến **n**.
- Bài 1 và Bài 2 nhập ma trận kề (0/1); Bài 3 nhập danh sách cạnh có trọng số.
- Đồ thị là đơn đồ thị vô hướng nên ma trận kề đối xứng và đường chéo bằng 0.
- Phần giải tay và ảnh chụp kết quả chạy chương trình nằm trong file báo cáo `Bài_làm_-_Nhóm_3`.
