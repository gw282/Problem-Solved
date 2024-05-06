def solution(numbers):
    answer = 0
    for num in numbers:
        answer += num
        
    answer /= len(numbers)
    return answer