def solution(n):
    answer = 0
    num = 1
    for i in range(1,12):
        num *= i
        if num > n:
            answer =i -1
            break
    return answer