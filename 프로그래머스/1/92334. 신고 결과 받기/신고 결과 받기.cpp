#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    // 중복 신고를 제거
    unordered_set<string> once;
    for (string s : report) {
        once.insert(s);
    }
    
    // 누구를 신고했는지 저장
    unordered_map<string, unordered_set<string>> reports;
    for (string s : once) {
        int i = s.find(' ');
        string reported = s.substr(i + 1);
        string reporter = s.substr(0, i);
        reports[reported].insert(reporter);
    }
    
    // 신고된 사람들의 신고 횟수 카운트
    unordered_map<string, int> reportedid;
    for (auto& entry : reports) {
        reportedid[entry.first] = entry.second.size();  // 신고 횟수는 각 사람을 신고한 사람들의 수
    }
    
    // 정지된 사람 찾기
    unordered_set<string> suspendedid;
    for (auto& entry : reportedid) {
        if (entry.second >= k) {
            suspendedid.insert(entry.first);  // 신고 횟수가 k 이상인 사람
        }
    }
    
    // 각 사람이 정지시킨 횟수 계산
    unordered_map<string, int> last;
    for (auto& entry : reports) {
        if (suspendedid.find(entry.first) != suspendedid.end()) {  // 신고된 사람이 정지되었다면
            for (const string& reporter : entry.second) {
                last[reporter]++;  // 그 사람을 신고한 사람은 정지시키는 횟수가 증가
            }
        }
    }
    
    // 결과 계산
    for (string s : id_list) {
        answer.push_back(last[s]);  // 각 사람이 신고한 횟수를 추가
    }
    
    return answer;
}