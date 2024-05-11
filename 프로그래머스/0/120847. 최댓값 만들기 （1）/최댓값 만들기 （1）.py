def solution(numbers):
    answer = 0
    
    for i in range(len(numbers)):
        for j in range(len(numbers)):
            if answer < numbers[i]*numbers[j] and i!=j:
                answer = numbers[i]*numbers[j]
    return answer