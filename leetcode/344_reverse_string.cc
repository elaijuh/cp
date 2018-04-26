// Source : https://leetcode.com/problems/reverse-string/
// Date   : 2016-06-30

class Solution {
public:
    string reverseString(string s) {
        int l = s.size();
        char c;
        for (int i=0; i<l/2; i++) {
            c = s[i];
            s[i] = s[l-i-1];
            s[l-i-1] = c;
        }
        return s;
    }
};
