// LeetCode 231: Power of Two

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (n != 1) {
            if (n&1) return false;
            n = n >> 1;
        }
        return true;
    }
};

/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && (!n&(n-1));
    }
};
*/