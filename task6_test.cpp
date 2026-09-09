#include <iostream>
#include <vector>

using namespace std;

vector<int> mode(int arr[], int n);

void print(vector<int> a) {
    if (a.size() == 0) {
        cout << "No mode";
    }

    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    cout << endl;
}

int main() {
    int a[] = {1, 2, 2, 2, 3, 4};
    cout << "Unique mode: ";
    print(mode(a, 6));

    int b[] = {1, 1, 2, 2, 3};
    cout << "Multiple modes: ";
    print(mode(b, 5));

    int c[1];
    cout << "Empty array: ";
    print(mode(c, 0));

    return 0;
}
