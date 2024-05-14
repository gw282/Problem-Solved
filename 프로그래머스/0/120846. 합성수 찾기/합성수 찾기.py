def solution(n):
    answer = 0
    d = 0
    for i in range(3,n+1):
        for j in range(1,i+1):
            if i % j == 0:
                d =  d+1
            if d > 2:
                answer += 1
                d = 0
                break
                
    return answer