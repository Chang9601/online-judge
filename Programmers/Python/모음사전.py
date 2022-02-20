def go(word,vowels,idx,l):
    if idx > len(vowels):
        return
    l.append(word)

    for i in range(0,len(vowels)):
        go(word+vowels[i],vowels,idx+1,l)

def solution(word):
    vowels = 'AEIOU'
    l = []
    go("",vowels,0,l)

    return l.index(word)
