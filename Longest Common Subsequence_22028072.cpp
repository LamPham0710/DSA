#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int m, int n, vector<vector<int>>& len) {
    if(m == 0 || n == 0) {
        return 0;
    }
    // nếu tồn tại trong mảng nghĩa là đã duyệt qua rồi, dùng luôn không cần tính lại.
    if(len[m][n] != -1) {
        return len[m][n];
    }
    // nếu 2 phần tử cuối 2 dãy trùng nhau thì lcs = 1 + lcs cặp dãy con.
    if(a[m - 1] == b[n - 1]) {
        return len[m][n] = 1 + lcs(a, b, m - 1, n - 1, len);

    }
    // 2 phần tử cuối 2 dãy không trùng thì lcs = max lcs của 2 cặp dãy con.
    return len[m][n] = max(lcs(a, b, m - 1, n, len), lcs(a, b, m, n - 1, len));


}

int main() {
    string a, b;
    cin >> a >> b;
    int m = a.size();
    int n = b.size();
    vector<vector<int>> len(m + 5, vector<int>(n + 5, -1));

    cout << lcs(a, b, m, n, len);

    return 0;
}
