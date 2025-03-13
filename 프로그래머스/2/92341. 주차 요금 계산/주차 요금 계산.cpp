#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    int DefaultTime = fees[0];  // 기본 시간 (분)
    int DefaultFee = fees[1];   // 기본 요금 (원)
    int UnitMinute = fees[2];   // 단위 시간 (분)
    int UnitFee = fees[3];      // 단위 요금 (원)
    
    map<string, int> parking;  // 각 차량별 주차 시간 저장
    map<string, int> entryTime;  // 각 차량의 입차 시간 저장
    
    // 입/출차 기록 처리
    for (string record : records) {
        string timeStr = record.substr(0, 5);  // "HH:MM"
        string carNumber = record.substr(6, 4);  // 차량 번호
        string action = record.substr(11, 2);  // "IN" 또는 "OUT"
        
        int hour = stoi(timeStr.substr(0, 2));
        int minute = stoi(timeStr.substr(3, 2));
        int time = hour * 60 + minute;  // "HH:MM"을 분으로 변환
        
        if (action == "IN") {
            // 차량 입차 시간 기록
            entryTime[carNumber] = time;
        } else {  // OUT
            // 차량 출차 시간 계산
            int parkedTime = time - entryTime[carNumber];
            parking[carNumber] += parkedTime;
            entryTime.erase(carNumber);  // 출차 후 입차 기록 삭제
        }
    }
    
    // 출차 기록이 없는 차량은 23:59에 출차된 것으로 간주
    for (auto& entry : entryTime) {
        int parkedTime = (23 * 60 + 59) - entry.second;  // 23:59에서 출차 시간 계산
        parking[entry.first] += parkedTime;
    }
    
    // 차량 번호 순으로 주차 요금을 계산
    for (auto& entry : parking) {
        string carNumber = entry.first;
        int parkedTime = entry.second;
        
        int fee = DefaultFee;
        
        if (parkedTime > DefaultTime) {
            int extraTime = parkedTime - DefaultTime;
            int extraFee = (int)ceil((double)extraTime / UnitMinute) * UnitFee;
            fee += extraFee;
        }
        
        answer.push_back(fee);
    }
    
    return answer;
}