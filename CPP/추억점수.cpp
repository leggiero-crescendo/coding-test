#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string,int> yearningMap;
    for(int i=0;i<name.size();i++) //dictionary 로 먼저 만들기 위함
        yearningMap[name[i]] = yearning[i];

    for(auto poto : photo){ // photo 사진을 행을 기준으로 먼저 짜르는 과정 
        int yearningPoint =0;
        for(auto person : poto){ // poto에 대해서 각 person을 불러옴 
            yearningPoint+=yearningMap[person]; //dictionary 니깐 그냥 값 불러오기 해서 합 치면 됨 
        }
        answer.push_back(yearningPoint); // answer은 vector로 표현된 값이기 때문에 그냥 값 넣으면 됨 
    }
    return answer;
}
