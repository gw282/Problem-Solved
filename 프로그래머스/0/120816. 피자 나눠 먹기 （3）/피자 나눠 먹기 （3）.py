def solution(slice, n):
    answer = 0
    if n%slice == 0:
        answer = n/slice
    else:
        answer = 1 +int(n/slice)
    return answer