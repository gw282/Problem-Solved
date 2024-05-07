def solution(array):
    answer = 0
    array.sort()
    answer = array[(int(len(array)/2))]
    return answer