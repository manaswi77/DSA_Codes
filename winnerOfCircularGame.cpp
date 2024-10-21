#include <iostream>
#include <queue>

class Solution {
public:
    int findTheWinner(int n, int k) {
        std::queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        while (n != 1) {
            for (int i = 0; i < k - 1; i++) {
                int f = q.front();
                q.pop();
                q.push(f);
            }
            q.pop(); // Eliminate the k-th person
            n--;
        }
        return q.front(); // The winner
    }
};

int main() {
    Solution solution;
    int n, k;
    
    std::cout << "Enter the number of players (n): ";
    std::cin >> n;
    std::cout << "Enter the elimination step (k): ";
    std::cin >> k;

    int winner = solution.findTheWinner(n, k);
    std::cout << "The winner is player " << winner << std::endl;

    return 0;
}
