def solution(num_list, n):
    answer = [[]]
    num = 0
    limit = 0
    for i in num_list:
        if limit<n:
            answer[num].append(i)
            limit += 1
        else:
            num += 1
            answer.append([])
            answer[num].append(i)
            limit = 1
    return answer

