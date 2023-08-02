class Solution {
public:
    int hammingWeight(uint32_t n) {
        //credit to its_vishal_7575
        //n%2, n>>=1
        //TC O(n), SC O(1)
        int count = 0;
        while(n){
            count += n%2;
            n >>= 1;
        }
        return count;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        //credit to its_vishal_7575 && housed
        //n%2, n>>=1
        //TC O(logN), SC O(1)
        int count = 0;
        while(n){
            //n & (n - 1) drops the lowest set bit. It's a neat little bit trick.
            n &= (n-1);
            count++;
        }
        return count;
    }
};