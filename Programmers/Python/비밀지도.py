def solution(n, arr1, arr2):
    ans = []

    for i in range(0,n):
        num = arr1[i] | arr2[i]
        s = ''
        for x in range(0,n):
            if ((num >> x) & 1) == 1:
                s += '#'
            else:
                s += ' '
        s = ''.join(list(reversed(s)))
        ans.append(s)

    return ans
