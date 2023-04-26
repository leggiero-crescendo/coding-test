/* 
💡 Targets
- A로부터 받은 공격 미사일을 격추하는 최소 요격 미사일 수를 return하라
- y 축에 수평인 미사일로 공격하여 한번에 요격가능하며, 개구간 내에서만 가능함

🔑 Strategy
- 요격범위를 활용하여 미사일 범위를 조정함
- 미사일 범위에 맞춰 요격 범위를 좁히고, 범위 안에 들어오는 미사일만 처리

🔑 Solution
1) 미사일의 시작위치를 기준으로 오름차순으로 정렬함
2) 반복문을 돌며 미사일의 길이 범위를 검사
3) 미사일 요격 범위로 잡은 후 미사일 길이 범위에 따라 요격범위 축소
4) 요격 범위를 이탈하는 미사일이 등장하면 새로운 요격 범위 갱신 (answer++)
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    return answer;
}
