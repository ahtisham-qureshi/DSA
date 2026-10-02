class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;

        int dir[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!q.empty()) {
            int k = q.size();

            while (k--) {
                auto [x, y] = q.front();
                q.pop();

                if (!(x == entrance[0] && y == entrance[1]) &&
                    (x == 0 || x == m - 1 || y == 0 || y == n - 1)) {
                    return steps;
                }

                for (auto &d : dir) {
                    int dx = x + d[0];
                    int dy = y + d[1];

                    if (dx < 0 || dx >= m || dy < 0 || dy >= n)
                        continue;

                    if (maze[dx][dy] == '+')
                        continue;

                    maze[dx][dy] = '+';
                    q.push({dx, dy});
                }
            }

            steps++;
        }

        return -1;
    }
};