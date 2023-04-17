/* 
💡 Targets
- 문자열에 포함되어있는 숫자를 "최소값 최댓값"의 형태로 반환하라

🔑 Strategy
- 문자열 -> split -> int -> " min max "

🔑 Method
- sstream을 활용한 문자열 split

*/

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<string> split(string str, char delimiter);
    vector<string> result = split(s, ' ');
    vector<double> re_double;

    for (int i=0; i<result.size();i++){
        double d = std::stof(result[i]);
        re_double.push_back(d);

    }
    int max_result = *max_element(re_double.begin(), re_double.end());
    int min_result = *min_element(re_double.begin(), re_double.end());
    
    answer = to_string(min_result) + ' ' + to_string(max_result);
    return answer;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

// 정수형 실수형을 변환해주는 함수 https://blockdmask.tistory.com/333 
