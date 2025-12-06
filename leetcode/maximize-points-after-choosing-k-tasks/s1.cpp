#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        vector<int> a;
        ll ans=0;
        int n=technique1.size();

        for(int i=0;i<n;++i) {
            a.push_back(technique1[i]-technique2[i]);
            ans+=technique1[i]>=technique2[i]?technique1[i]:technique2[i];
        }
        sort(a.begin(),a.end());
        for(int i=n-1;i>=n-k;--i) {
            if(a[i]<0) ans+=a[i];
        }
        return ans;

    }
};
