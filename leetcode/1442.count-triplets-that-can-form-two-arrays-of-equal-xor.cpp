/*
 * @lc app=leetcode id=1442 lang=cpp
 *
 * [1442] Count Triplets That Can Form Two Arrays of Equal XOR
 *
 * https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
 *
 * algorithms
 * Medium (62.70%)
 * Likes:    73
 * Dislikes: 3
 * Total Accepted:    5.4K
 * Total Submissions: 8.7K
 * Testcase Example:  '[2,3,1,6,7]'
 *
 * Given an array of integers arr.
 *
 * We want to select three indices i, j and k where (0 <= i < j <= k <
 * arr.length).
 *
 * Let's define a and b as follows:
 *
 *
 * a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
 * b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
 *
 *
 * Note that ^ denotes the bitwise-xor operation.
 *
 * Return the number of triplets (i, j and k) Where a == b.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [2,3,1,6,7]
 * Output: 4
 * Explanation: The triplets are (0,1,2), (0,2,2), (2,3,4) and (2,4,4)
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,1,1,1,1]
 * Output: 10
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [2,3]
 * Output: 0
 *
 *
 * Example 4:
 *
 *
 * Input: arr = [1,3,5,7,9]
 * Output: 3
 *
 *
 * Example 5:
 *
 *
 * Input: arr = [7,11,12,9,5,2,7,17,22]
 * Output: 8
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 300
 * 1 <= arr[i] <= 10^8
 *
 */

// @lc code=start
/**
 * method 1: brute force + 标记结果

class Solution {
public:
    int getXor(vector<int>& arr, int l, int r) {
        int a=arr[l];
        for (int i=l+1;i<=r;i++) a^=arr[i];
        return a;
    }

    int countTriplets(vector<int>& arr) {
        int d[300][300]={0};
        for (int i=0;i<300;i++)
            for (int j=0;j<300;j++)
                d[i][j]=-1;
        int n=arr.size();
        int cnt=0;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                for (int k=j;k<n;k++) {
                    int a,b;
                    if (d[i][j-1]!=-1) a=d[i][j-1];
                    else {
                        a=getXor(arr, i, j-1);
                        d[i][j-1]=a;
                    }
                    if (d[j][k]!=-1) b=d[j][k];
                    else {
                        b=getXor(arr, j, k);
                        d[j][k]=b;
                    }
                    if (a==b) cnt++;
                }
        return cnt;

    }
};
*/

class Solution {
 public:
  int countTriplets(vector<int>& arr) {
    arr.insert(arr.begin(), 0);
    for (int i = 1; i < arr.size(); i++) arr[i] ^= arr[i - 1];
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
      for (int k = i + 1; k < arr.size(); k++)
        if (arr[i] == arr[k]) ans += k - i - 1;
    return ans;
  }
};

/**
 * method 3: O(n) based on method 2
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, int> count, total;
        arr.insert(arr.begin(), 0);
        int ans=0;
        int cur=0;
        for (int i=0;i<arr.size();i++) {
            cur^=arr[i];
            ans+=(count[cur]++)*(i-1)-total[cur];
            total[cur]+=i;
        }
        return ans;
    }
};
*/
// @lc code=end
