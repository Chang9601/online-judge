def solution(n):
    m = n+1

    while bin(n).count('1') != bin(m).count('1'):
        m += 1
    return m
