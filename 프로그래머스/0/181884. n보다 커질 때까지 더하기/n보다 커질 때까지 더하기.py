def solution(numbers, n):
    answer = 0
    
    for i in numbers:
        if answer > n:
            break
        answer += i
    return answer