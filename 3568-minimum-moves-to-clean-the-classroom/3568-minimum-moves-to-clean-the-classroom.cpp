class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        pair<int, int> start;
        vector<pair<int, int>> litter;
        map<pair<int, int>, int> lit_id;
        int l = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(classroom[i][j] == 'S') {
                    start = {i, j};
                }
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                    lit_id[{i, j}] = l++;
                }
            }
        }

        bool vis[20][20][1 << 10][51];
        memset(vis, false, sizeof(vis));

        struct State {
            int x, y, mask, e, d;
        };

        queue<State> q;
        vis[start.first][start.second][0][energy] = true;
        q.push({start.first, start.second, 0, energy, 0});
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()) {
            State u = q.front(); q.pop();
            if(u.mask == ((1<<l)-1)) return u.d;
            if(u.e == 0) continue;
            
            for(auto &dir : dirs) {
                int nx = u.x + dir[0];
                int ny = u.y + dir[1];

                if(nx < 0 || nx >= m || ny < 0 || ny >= n || classroom[nx][ny] == 'X') continue;

                int ne = u.e - 1;
                if(classroom[nx][ny] == 'R') ne = energy;

                int nmask = u.mask;
                if(classroom[nx][ny] == 'L') {
                    nmask |= (1 << lit_id[{nx, ny}]);
                }

                if(!vis[nx][ny][nmask][ne]) {
                    vis[nx][ny][nmask][ne] = true;
                    q.push({nx, ny, nmask, ne, u.d + 1});
                }
            }
        }

        return -1;
    }
};