#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startR = -1, startC = -1;
        vector<pair<int, int>> litters;
        
        // Locate starting position and assign indices to litter items
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    litters.push_back({r, c});
                }
            }
        }
        
        int numLitter = litters.size();
        int targetMask = (1 << numLitter) - 1;
        
        // Map (row, col) of litter to its index bit
        auto getLitterIndex = [&](int r, int c) {
            for (int i = 0; i < numLitter; ++i) {
                if (litters[i].first == r && litters[i].second == c) {
                    return i;
                }
            }
            return -1;
        };
        
        // State visited table: max energy recorded at (r, c, mask)
        // Initialize with -1
        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << numLitter, -1)));
        
        // Queue stores tuple: {r, c, mask, current_energy}
        queue<tuple<int, int, int, int>> q;
        
        int initialMask = 0;
        bestEnergy[startR][startC][initialMask] = energy;
        q.push({startR, startC, initialMask, energy});
        
        int steps = 0;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();
                
                // If all litter items are collected, return total steps
                if (mask == targetMask) {
                    return steps;
                }
                
                // If energy is depleted and not on a Reset cell, cannot move further
                if (e == 0) {
                    continue;
                }
                
                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    
                    // Check bounds and obstacle
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                        continue;
                    }
                    
                    int nextEnergy = e - 1;
                    int nextMask = mask;
                    char cell = classroom[nr][nc];
                    
                    // Collect litter
                    if (cell == 'L') {
                        int idx = getLitterIndex(nr, nc);
                        if (idx != -1) {
                            nextMask |= (1 << idx);
                        }
                    }
                    
                    // Reset energy
                    if (cell == 'R') {
                        nextEnergy = energy;
                    }
                    
                    // Only push if we achieve strictly greater energy for this state
                    if (nextEnergy > bestEnergy[nr][nc][nextMask]) {
                        bestEnergy[nr][nc][nextMask] = nextEnergy;
                        q.push({nr, nc, nextMask, nextEnergy});
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};