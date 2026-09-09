#include <string>

using namespace std;

int search(string text, string pat) {
    if (pat.length() == 0) {
        return 0;
    }

    if (pat.length() > text.length()) {
        return -1;
    }

    int n = text.length();
    int m = pat.length();

    for (int i = 0; i <= n - m; i++) {
        int check = 1;

        for (int j = 0; j < m; j++) {
            if (text[i + j] != pat[j]) {
                check = 0;
                break;
            }
        }

        if (check == 1) {
            return i;
        }
    }

    return -1;
}
