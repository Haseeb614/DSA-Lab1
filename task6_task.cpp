#include <vector>

using namespace std;

vector<int> mode(int arr[], int n) {
    vector<int> ans;
    int max = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > max) {
            ans.clear();
            ans.push_back(arr[i]);
            max = count;
        } else if (count == max) {
            int check = 0;

            for (int j = 0; j < ans.size(); j++) {
                if (ans[j] == arr[i]) {
                    check = 1;
                }
            }

            if (check == 0) {
                ans.push_back(arr[i]);
            }
        }
    }

    return ans;
}
