def solution(n):
    answer = []
    for i in range(n):
        if n%(n-i) == 0:
            answer.append(n/(n-i))
    return answer