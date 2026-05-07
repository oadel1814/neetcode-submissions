#include <iostream>
#include <string>
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (string &s : strs) {
            int len = (int)s.size();
            encoded += to_string(len) + '#';
            for (char &c : s) {
                encoded += c;
            }
        }

        cout << encoded << '\n';
        return encoded;
    }

    vector<string> decode(string s) {
        if (s.empty()) {
            return {};
        }

        vector<string> decoded;
        int i = 0;
        while (i + 1 < s.size()) {
            int j = i;
            string len;
            while (j + 1 < s.size() && s[j] != '#') {
                len += s[j++];
                i++;
            }

            cout << len << '\n';

            int sz = std::stoi(len);
            // cout << sz << '\n';

            int end = j + 1;
            string cur;
            while (end - j - 1 < sz) {
                cur += s[end++];
            }

            decoded.push_back(cur);
            i += sz + 1;
        }

        return decoded;
    }
};
