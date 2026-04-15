class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int MAX = 200000;
        vector<bool> isPrime = sieve(MAX);

        int ops = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            if (i % 2 == 0) {
                while (!isPrime[x]) x++;
            } else {
                while (isPrime[x]) x++;
            }

            ops += (x - nums[i]);
        }

        return ops;
    }
};