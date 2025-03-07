#include <string>
#include <stack>
#include <iostream>

using namespace std;

// 올바른 괄호 문자열인지 체크하는 함수
bool isValid(const string& s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c); // 여는 괄호는 스택에 넣음
        } else {
            if (st.empty()) return false; // 스택이 비어있다면 잘못된 괄호
            char top = st.top();
            st.pop();
            
            // 짝이 맞지 않으면 잘못된 괄호
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return st.empty(); // 스택이 비어있으면 올바른 괄호 문자열
}

int solution(string s) {
    int count = 0;
    int n = s.size();
    
    // 문자열을 회전시키며 올바른 괄호 문자열인지 체크
    for (int i = 0; i < n; ++i) {
        // s를 i번 만큼 회전
        string rotated = s.substr(i) + s.substr(0, i);
        
        // 올바른 괄호 문자열이면 카운트 증가
        if (isValid(rotated)) {
            count++;
        }
    }
    
    return count;
}

int main() {
    cout << solution("[](){}") << endl; // 3
    cout << solution("}]()[{") << endl; // 2
    cout << solution("[)(]") << endl;   // 0
    cout << solution("}}}") << endl;     // 0
    return 0;
}