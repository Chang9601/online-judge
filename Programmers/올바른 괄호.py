def solution(s):
    ct = 0

    for c in s:
        if c == '(':
            ct += 1
        else:
            ct -= 1

        if ct < 0:
            return False
    return ct == 0
