def go(numbers,target,size,idx,tot):
    if(size == idx):
        if(target == tot):
            return 1
        else:
            return 0

    return go(numbers,target,size,idx+1,tot+numbers[idx])+go(numbers,target,size,idx+1,tot-numbers[idx])

def solution(numbers, target):
    return go(numbers,target,len(numbers),0,0)
