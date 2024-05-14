def solution(n):
    answer = 0
    
    answer = lcm(n,6)/6
    return answer

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(x, y):
    return x * y // gcd(x, y)