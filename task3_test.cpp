#include <iostream>
#include <vector>
#include "task3_task.h"
using namespace std;

vector<int> function(int arr[], int size, int key);

int main() {
    int arr1[] = {10, 20, 30, 20, 40, 20, 50};
    vector<int> res1 = function(arr1, 7, 20);
    for (int x : res1) cout << x << " ";
    cout << "\n";

    int arr2[] = {1, 2, 3, 4, 5};
    vector<int> res2 = function(arr2, 5, 99);
    for (int x : res2) cout << x << " ";
    cout << "\n";

    int arr3[] = {};
    vector<int> res3 = function(arr3, 0, 5);
    for (int x : res3) cout << x << " ";
    cout << "\n";

    return 0;
}
