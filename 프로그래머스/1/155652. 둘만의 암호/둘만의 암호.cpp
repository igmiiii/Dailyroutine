#include <string>
#include <unordered_set>

using namespace std;

string solution(string s, string skip, int index) {
    string result = "";
    unordered_set<char> skipSet; // skip에 포함된 알파벳들을 저장할 set

    // skip 문자열에 포함된 알파벳을 set에 넣기
    for (char c : skip) {
        skipSet.insert(c);
    }

    for (char c : s) {
        int count = 0;
        while (count < index) {
            c = (c == 'z') ? 'a' : c + 1; // z를 넘어가면 a로 돌아감
            if (skipSet.find(c) == skipSet.end()) { // skip에 포함되지 않으면
                count++;
            }
        }
        result += c;
    }

    return result;
}