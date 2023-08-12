#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int minimax(int depth, int nodeIndex, bool isMaximizer, int values[], int alpha, int beta) {
    if (depth == 0) {
        return values[nodeIndex];
    }

    if (isMaximizer) {
        int maxEval = -INF;
        for (int i = 0; i < 2; i++) {
            int eval = minimax(depth - 1, nodeIndex * 2 + i, false, values, alpha, beta);
            maxEval = max(maxEval, eval);
            alpha = max(alpha, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return maxEval;
    } else {
        int minEval = INF;
        for (int i = 0; i < 2; i++) {
            int eval = minimax(depth - 1, nodeIndex * 2 + i, true, values, alpha, beta);
            minEval = min(minEval, eval);
            beta = min(beta, eval);
            if (beta <= alpha) {
                break;
            }
        }
        return minEval;
    }
}

int main() {
    int depth = 3;  // Depth of the game tree
    int values[] = {3, 5, 2, 9, 12, 5, 23, 23};  // Leaf node values

    int result = minimax(depth, 0, true, values, -INF, INF);
    cout << "The optimal value for the first player is: " << result << endl;

    return 0;
}

