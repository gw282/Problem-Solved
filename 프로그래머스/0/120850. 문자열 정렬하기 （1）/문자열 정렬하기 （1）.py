def solution(my_string):
    answer = []
    
    for i in my_string:
        if i <='9' and i>='0':
            answer.append(int(i))
        answer.sort()
    return answer