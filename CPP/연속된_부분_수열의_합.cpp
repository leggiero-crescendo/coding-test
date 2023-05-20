/*
💡 Targets
- 비내림차순(오름차순과는 다름 반복된 수가 있을 수도 있음 : 오름차순은 증가하는 형태임)의 수열 중 합이 k인 수열을 찾아라
- 부분 수열의 합을 나타내는 정수 k가 매개변수로 주어질 때 시작인덱스와 마지막 인덱스를 배열에 담아 return 
=> 단, 합이 k 인 부분 수열이 여러개일 경우 1) 길이가 짧음 2) 길이가 동일하면 앞쪽에 나오는 수열 

🔑 Strategy
- 구하려는 부분 수열의 시작 s, 끝 e  0으로 초기화
- 부분 수열합 sum -> sequence[0]으로 초기화
- 수열의 길이 sumLen 

🔑 Solution
- 오랜만에 풀어서 잘 모르겠다. 
- 일주일에 한개이상은 고민해 보자
(https://cherishvert.tistory.com/89 -> 링크의 코드를 참
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int s = 0;
    int e = 0;
    int sum = sequence[0];
    int sumLen = sequence.size() + 1;
    pair<int, int> answer;
    while(s <= e && e < sequence.size()){
        if (sum < k){
            sum += sequence[++e];
        }
        else if(sum == k){
            if (e-s+1 < sumLen){
                sumLen = e-s+1;
                answer = {s, e};
            }
            else if(e-s+1 == sumLen){
                if (s < answer.first){
                    answer = {s, e};
                }
            }
            sum -= sequence[s++];
        } 
        else sum -= sequence[s++];
    

    }

    return {answer.first, answer.second};
}
