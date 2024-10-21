#include <iostream>
#include <limits.h> // For INT_MIN and INT_MAX

class Solution {
public:
    int reverse(int x) {
        int ans = 0; // This will hold the reversed number
        while (x != 0) {
            int r = x % 10; // Get the last digit
            // Check for overflow or underflow before updating ans
            if (ans > (INT_MAX / 10) || (ans == INT_MAX / 10 && r > 7)) {
                return 0; // Overflow for positive integers
            }
            if (ans < (INT_MIN / 10) || (ans == INT_MIN / 10 && r < -8)) {
                return 0; // Underflow for negative integers
            }
            ans = (ans * 10) + r; // Append the digit to the reversed number
            x /= 10; // Remove the last digit from x
        }
        return ans; // Return the reversed integer
    }
};

