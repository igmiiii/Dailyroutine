#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> playerIndex; // 플레이어의 이름을 키로, 인덱스를 값으로 저장

    // players 벡터를 순회하며 각 플레이어의 인덱스를 저장
    for (int i = 0; i < players.size(); ++i) {
        playerIndex[players[i]] = i;
    }

    // callings을 처리하여 각 플레이어의 위치를 교환
    for (string s : callings) {
        int idx = playerIndex[s]; // 현재 플레이어의 인덱스를 찾음
        
            // 현재 플레이어와 그 앞의 플레이어를 교환
            swap(players[idx], players[idx - 1]);
            playerIndex[players[idx]] = idx;          // 새로운 인덱스를 갱신
            playerIndex[players[idx - 1]] = idx - 1;  // 새로운 인덱스를 갱신
        
    }

    // players 벡터를 answer에 추가
    return players;
}