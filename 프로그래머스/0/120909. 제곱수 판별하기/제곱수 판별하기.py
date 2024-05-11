def solution(n):
    answer = 2
    
    for i in range(n):
        if i*i == n:
            answer = 1
            break
    return answer