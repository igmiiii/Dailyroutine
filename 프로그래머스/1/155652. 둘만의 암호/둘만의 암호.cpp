#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    
    
    for (char c : s) {
        char new_char = c;  // 현재 문자 c를 새로운 문자로 처리할 변수

        // 문자를 index만큼 이동시키기
        for (int i = 0; i < index; ++i) {
            new_char++;  // 문자 하나씩 이동

            // 'z'를 넘어가면 'a'로 돌아가기
            if (new_char > 'z') {
                new_char = 'a';
            }

            // 만약 'skip'에 포함된 문자라면, 건너뛰고 계속 이동
            while (skip.find(new_char) != string::npos) {
                new_char++;  // skip에 포함되었으면 다음 문자로 이동
                if (new_char > 'z') {
                    new_char = 'a';  // 다시 'a'로 돌아가기
                }
            }
        }

        // 새로 계산된 문자를 결과에 추가
        answer += new_char;
    }

    return answer;
}