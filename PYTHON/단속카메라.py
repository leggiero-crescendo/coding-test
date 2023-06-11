'''
car : 1 ~ 10,000
routes[i][0] : in
routes[i][1] : out
in-out range [-30,000, 30,000]

** 문제접근
- 차량이 최대한 많이 잡히는 지점에 단속카메라를 설치하는 것이 좋음
- routes를 진출 지점을 기준으로 정렬하여 카메라에 걸리는지 확인

(https://wwlee94.github.io/category/algorithm/greedy/speed-enforcement-camera/)
** 문제풀이
1. 진출 지점 기준으로 오름 차순 정렬합니다. (routes[1] 기준)
2. 최대 -30000이니 초기 카메라 위치를 -30001로 초기화 해줍니다.
3. routes 배열을 반복하면서 카메라가 진입 지점(route[0])보다 작은지 확인합니다.
4. 작다면, 현재 카메라 위치로 해당 차량을 만나지 못했다는 의미이니
    4-1. 카메라를 추가로 세우고
    4-2. 가장 최근 카메라의 위치(route[1])를 갱신합니다.

'''
def solution(routes):
    answer = 0
    routes.sort(key=lambda x: x[1]) # routes를 차량이 나간 지점 (진출) 기준으로 정렬
    camera = -30001 # -30001부터 카메라 위치를 찾습니다.

    for route in routes:
        if camera < route[0]:
            answer += 1
            camera = route[1]
    return answer

# def solution(routes):
#     answer = 0
#     tmp = 0
#     routes_tmp = []
#     tmp_list = []
#     for rout in routes:
#         routes_tmp = list(range(rout[0], rout[1]))
#         if len(tmp_list)!=0:
#             for tmps in tmp_list:
#                 if tmps in routes_tmp:
#                     tmp += 1
#             if tmp == 0:
#                 tmp_list.append(rout[1] if abs(rout[0]) > abs(rout[1]) else rout[0])
#             else:
#                 tmp = 0
#         else:
#             tmp_list.append(rout[1] if abs(rout[0]) > abs(rout[1]) else rout[0]) 
#     answer = len(tmp_list)
#     return answer
