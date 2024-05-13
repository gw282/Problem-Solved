def solution(numbers, direction):
    answer = []
    if direction == 'right':
        answer = numbers[len(numbers)-1::] + numbers[:-1]
    else:
        answer = numbers[1::] + numbers[0:1:]
    return answer