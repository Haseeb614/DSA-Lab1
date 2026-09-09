#include <vector>

using namespace std;

vector<int> function(int array[], int size, int key) {
    vector<int> required_vector;
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            required_vector.push_back(i);
        }
    }
    return required_vector;
}
