#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 상, 하, 좌, 우 방향 (4방향)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, vector<string>& maps, vector<vector<bool>>& visited, int& island_food) {
    // 현재 칸을 방문처리
    visited[x][y] = true;
    
    // 현재 칸의 음식량 더하기
    island_food += maps[x][y] - '0';  // char -> int 변환
    
    // 상, 하, 좌, 우 탐색
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 유효한 범위 내에서 방문하지 않은 무인도(숫자)가 있으면 DFS 탐색
        if (isValid(nx, ny, maps.size(), maps[0].size()) && !visited[nx][ny] && maps[nx][ny] != 'X') {
            dfs(nx, ny, maps, visited, island_food);
        }
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n = maps.size();
    int m = maps[0].size();
    
    // 방문 여부 체크용 2D 벡터
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // 모든 칸을 탐색하면서 섬을 찾아낸다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] != 'X' && !visited[i][j]) {
                // 섬을 찾았을 경우 DFS 탐색
                int island_food = 0;
                dfs(i, j, maps, visited, island_food);
                answer.push_back(island_food);
            }
        }
    }
    
    // 섬이 하나도 없다면 -1을 반환
    if (answer.empty()) {
        answer.push_back(-1);
    } else {
        // 섬들의 음식량 합을 오름차순으로 정렬
        sort(answer.begin(), answer.end());
    }
    
    return answer;
}