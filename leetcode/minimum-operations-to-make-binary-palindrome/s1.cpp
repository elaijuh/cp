#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int n) {
        bitset<14> bp(n);
        string bs=bp.to_string();
        bs.erase(0, bs.find_first_not_of('0'));
        int l=bs.size();
        for(int i=0;i<l/2;++i) {
            if(bs[i]!=bs[l-i-1]) return false;
        }
        return true;
    }

    vector<int> minOperations(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();++i) {
            int mi=5001;
            int k=0;
            while(!check(nums[i]+k)) k++;
            mi=min(mi,k);
            k=0;
            while(!check(nums[i]-k)) k++;
            mi=min(mi,k);
            ans.push_back(mi);
        }
        return ans;
    }
};
