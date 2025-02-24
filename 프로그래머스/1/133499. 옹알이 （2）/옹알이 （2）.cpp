#include <string>
#include <vector>
using namespace std;

bool isValidBabbling(const string& word) {
    // 발음 가능한 단어들
    string valid[] = {"aya", "ye", "woo", "ma"};
    
    // 연속해서 같은 발음이 나오지 않도록
    string prev = ""; // 이전 발음
    size_t pos = 0;
    
    // word에서 발음을 하나씩 체크
    while (pos < word.size()) {
        bool found = false;
        for (const string& sound : valid) {
            // 현재 발음이 유효하고, 이전 발음과 다르면
            if (word.substr(pos, sound.size()) == sound && sound != prev) {
                prev = sound; // 현재 발음을 prev로 저장
                pos += sound.size(); // 그 발음만큼 이동
                found = true;
                break;
            }
        }
        
        // 유효한 발음을 찾지 못했으면 잘못된 단어
        if (!found) {
            return false;
        }
    }
    
    return true;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    // 각 단어에 대해 유효한 발음인지 확인
    for (const string& word : babbling) {
        if (isValidBabbling(word)) {
            answer++;
        }
    }
    
    return answer;
}