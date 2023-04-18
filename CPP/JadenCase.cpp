/* 
💡 Targets
- 단어의 첫문자를 모두 대문자로 변경하라(단, 첫단어가 숫자일 경우 그 이후 알파벳은 소문자)

🔑 Strategy
- 문자열 1개씩 체크 -> 모두 소문자 단 공백 다음은 대문자 (space_tmp로 공백이면 true를 반환)

🔑 Method
- 문자열 1개씩 끊어서 확인하기
    : str.at(i) using
- 대문자, 소문자, space 구별하는 방법
- 대문자 <-> 소문자 바꾸는 방법
*/

#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool space_tmp = false;
    
    for (int i=0; i<s.size();i++){
        if(std::isspace(s[i])!=0){
            space_tmp = true;
            answer += " ";
        }
        else if(space_tmp == true || i==0){
            answer += std::toupper(s[i]);
            space_tmp = false;
        }
        else{
            answer+= std::tolower(s[i]);
        }
    }
    return answer;
}
