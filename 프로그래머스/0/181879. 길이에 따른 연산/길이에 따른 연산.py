def solution(num_list):
    answer = 0
    
    if len(num_list) < 11:
        for i in num_list:
            if answer == 0:
                answer = 1
            answer *= i
    else:
        for i in num_list:
            answer += i
    return answer