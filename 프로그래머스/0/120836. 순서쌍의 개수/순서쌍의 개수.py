def solution(n):
    answer = 1
    for i in range(int(n/2)):
        if n%(i+1) == 0:
            answer+= 1
    return answer