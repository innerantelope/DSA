class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) {
            int divisor = 0;     
            int temp = 0;       
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    int j = num / i;

                    if (i == j) {   
                        divisor = 0;
                        break;
                    }

                    divisor += 2;
                    temp += i + j;

                    if (divisor > 2) break;
                }
            }

            if (divisor == 2) {
                sum += temp + 1 + num;
            }
        }

        return sum;
    }
};
