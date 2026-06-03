#include <iostream>
#include <set>
#include <cctype>
using namespace std;

bool isPangram(string str) {
    set<char> letters;

    for (char ch : str) {
        if (isalpha(ch)) {
            letters.insert(tolower(ch));
        }
    }

    return letters.size() == 26;
}

int main() {
    string str;
    getline(cin, str);

    if (isPangram(str))
        cout << "Pangram";
    else
        cout << "Not Pangram";

    return 0;
}