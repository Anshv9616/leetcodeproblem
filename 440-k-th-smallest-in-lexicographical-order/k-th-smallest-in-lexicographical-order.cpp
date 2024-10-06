class Solution {
private:
    long getCount(long prefix, long n) {
        long count = 0;
        long current = prefix, next = prefix + 1;

        while (current <= n) {
            count += min(n + 1, next) - current;
            current *= 10;
            next *= 10;
        }
        return count;
    }
    
public:
    int findKthNumber(int n, int k) {
        long prefix = 1;
        k--;  // Decrease k to make it zero-based

        while (k > 0) {
            long count = getCount(prefix, n);
            if (count <= k) {
                // Move to the next prefix
                prefix++;
                k -= count;  // Decrease k by the number of skipped counts
            } else {
                // Go down the tree
                prefix *= 10;
                k--;  // Decrease k for the prefix we just counted
            }
        }
        
        return static_cast<int>(prefix);
    }
};
