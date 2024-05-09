def solution(n):
    answer = 0

    while(n>=9):
        answer += n%10
        n = int(n/10)
    answer += n
    return answer