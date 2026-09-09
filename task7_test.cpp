#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> normal(vector<vector<int>> a, vector<vector<int>> b);
vector<vector<int>> strassen(vector<vector<int>> a, vector<vector<int>> b);

void print(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool same(vector<vector<int>> a, vector<vector<int>> b) {
    return a == b;
}

int main() {
    vector<vector<int>> a2 = {{1, 2}, {3, 4}};
    vector<vector<int>> b2 = {{5, 6}, {7, 8}};
    vector<vector<int>> c2 = strassen(a2, b2);
    cout << "2 x 2 result" << endl;
    print(c2);
    cout << "Matches normal multiplication: " << same(c2, normal(a2, b2)) << endl;

    vector<vector<int>> a4 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    vector<vector<int>> b4 = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    vector<vector<int>> c4 = strassen(a4, b4);
    cout << "4 x 4 result" << endl;
    print(c4);
    cout << "Matches normal multiplication: " << same(c4, normal(a4, b4)) << endl;

    srand(10);
    vector<vector<int>> a(4, vector<int>(4));
    vector<vector<int>> b(4, vector<int>(4));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    cout << "Random matrices match: " << same(strassen(a, b), normal(a, b)) << endl;

    return 0;
}
