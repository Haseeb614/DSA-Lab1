#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pascal(int n);

void print(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> a = pascal(0);
    cout << "n = 0" << endl;
    print(a);

    vector<vector<int>> b = pascal(1);
    cout << "n = 1" << endl;
    print(b);

    vector<vector<int>> c = pascal(5);
    cout << "n = 5" << endl;
    print(c);

    cout << "Row 5: ";
    for (int i = 0; i < c[4].size(); i++) {
        cout << c[4][i] << " ";
    }
    cout << endl;

    return 0;
}
