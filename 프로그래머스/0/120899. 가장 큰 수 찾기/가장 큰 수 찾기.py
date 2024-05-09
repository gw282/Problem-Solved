def solution(array):
    answer = []
    
    max_value = 0
    max_index = 0
    
    for index, value in enumerate(array):
        if value >= max_value:
            max_value = value
            max_index = index

    answer.append(max_value)
    answer.append(max_index)
    return answer