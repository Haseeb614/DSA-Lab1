#include <iostream>
#include <string>

using namespace std;

int search(string text, string pat);

int main() {
    cout << search("hello world", "hello") << endl;
    cout << search("hello world", "world") << endl;
    cout << search("hello world", "goodbye") << endl;
    cout << search("hello world", "") << endl;

    return 0;
}
