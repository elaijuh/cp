#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_prime(int n) {
        if(n<=1) return false;
        if(n==2) return true;
        if(n%2==0) return false;
        for(int i = 3;i<=sqrt(n);i+=2)
            if (n%i==0) return false;
        return true;
    }

    bool completePrime(int num) {
        for(int k=0;k<=9 && num>=pow(10,k);++k) {
            if(!is_prime(num/(int)pow(10,k))) return false;
        }
        for(int k=1;k<=9 && num>=pow(10,k);++k) {
            if(!is_prime(num%(int)pow(10,k))) return false;
        }
        return true;
    }
};
