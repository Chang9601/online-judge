def solution(record):
    arr = []
    m = {}

    for r in record:
        tokens = r.split(' ')
        cmd = tokens[0]

        if cmd == 'Enter':
            arr.append(tokens[1]+'님이 들어왔습니다.')
            m[tokens[1]] = tokens[2]
        elif cmd == 'Leave':
            arr.append(tokens[1]+'님이 나갔습니다.')
        else:
            m[tokens[1]] = tokens[2]

    ans = []
    for str in arr:
        index = str.find('님')
        sub = str[0:index]
        str = str.replace(sub,m[sub])
        ans.append(str)

    return ans
