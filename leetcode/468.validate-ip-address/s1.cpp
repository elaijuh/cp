// OJ: https://leetcode.com/problems/validate-ip-address/
// Author: github.com/elaijuh
// Time: O(n)
// Space: O()
class Solution {
 public:
  string validIPAddress(string IP) {
    istringstream is(IP);
    string s = "";
    int cnt = 0;
    if (IP.find(':') == string::npos) {
      while (getline(is, s, '.')) {
        ++cnt;
        if (cnt > 4 || s.empty() || (s.size() > 1 && s[0] == '0') ||
            s.size() > 3)
          return "Neither";
        for (char c : s)
          if (c < '0' || c > '9') return "Neither";
        int val = stoi(s);
        if (val < 0 || val > 255) return "Neither";
      }
      // return (cnt == 4 && IP.back() != '.') ? "IPv4" : "Neither";
      return cnt == 4 && IP.back() != '.' ? "IPv4" : "Neither";
    } else {
      while (getline(is, s, ':')) {
        ++cnt;
        if (cnt > 8 || s.empty() || s.size() > 4) return "Neither";
        for (char c : s)
          if (!(c >= '0' && c <= '9') && !(c >= 'A' && c <= 'F') &&
              !(c >= 'a' && c <= 'f'))
            return "Neither";
      }
      return cnt == 8 && IP.back() != ':' ? "IPv6" : "Neither";
    }
  }
};
