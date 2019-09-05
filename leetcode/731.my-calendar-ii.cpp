/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// |---------------|
//        |----|

class MyCalendarTwo {
 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    for (auto &x : intersect) {
      if (x.second > start && x.first < end) {
        return false;
      }
    }

    for (auto &x : segment) {
      if (x.second > start && x.first < end) {
        intersect.push_back({max(x.first, start), min(x.second, end)});
      }
    }

    segment.push_back({start, end});
    return true;
  }

 private:
  vector<pair<int, int>> segment;
  vector<pair<int, int>> intersect;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
