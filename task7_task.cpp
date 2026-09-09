#include <vector>

using namespace std;

vector<vector<int>> add(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = a[i][j] + b[i][j];
        }
    }

    return ans;
}

vector<vector<int>> sub(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = a[i][j] - b[i][j];
        }
    }

    return ans;
}

vector<vector<int>> normal(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ans[i][j] = ans[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    return ans;
}

vector<vector<int>> strassen(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();

    if (n == 1) {
        vector<vector<int>> ans(1, vector<int>(1));
        ans[0][0] = a[0][0] * b[0][0];
        return ans;
    }

    int half = n / 2;
    vector<vector<int>> a11(half, vector<int>(half));
    vector<vector<int>> a12(half, vector<int>(half));
    vector<vector<int>> a21(half, vector<int>(half));
    vector<vector<int>> a22(half, vector<int>(half));
    vector<vector<int>> b11(half, vector<int>(half));
    vector<vector<int>> b12(half, vector<int>(half));
    vector<vector<int>> b21(half, vector<int>(half));
    vector<vector<int>> b22(half, vector<int>(half));

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + half];
            a21[i][j] = a[i + half][j];
            a22[i][j] = a[i + half][j + half];
            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + half];
            b21[i][j] = b[i + half][j];
            b22[i][j] = b[i + half][j + half];
        }
    }

    vector<vector<int>> m1 = strassen(add(a11, a22), add(b11, b22));
    vector<vector<int>> m2 = strassen(add(a21, a22), b11);
    vector<vector<int>> m3 = strassen(a11, sub(b12, b22));
    vector<vector<int>> m4 = strassen(a22, sub(b21, b11));
    vector<vector<int>> m5 = strassen(add(a11, a12), b22);
    vector<vector<int>> m6 = strassen(sub(a21, a11), add(b11, b12));
    vector<vector<int>> m7 = strassen(sub(a12, a22), add(b21, b22));

    vector<vector<int>> c11 = add(sub(add(m1, m4), m5), m7);
    vector<vector<int>> c12 = add(m3, m5);
    vector<vector<int>> c21 = add(m2, m4);
    vector<vector<int>> c22 = add(sub(add(m1, m3), m2), m6);
    vector<vector<int>> ans(n, vector<int>(n));

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            ans[i][j] = c11[i][j];
            ans[i][j + half] = c12[i][j];
            ans[i + half][j] = c21[i][j];
            ans[i + half][j + half] = c22[i][j];
        }
    }

    return ans;
}
