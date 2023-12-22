def metgaego(T, S):
    if (0 <= T < 12) or (16 < T <= 23)  or S == 1:
        babal = 280
    else:
        babal = 320
        
    return babal
        
if __name__ == "__main__":
    T, S = map(int, input().split())
    
    print(metgaego(T=T, S=S))