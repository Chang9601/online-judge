def solution(new_id):
    new_id = new_id.lower()
    
    p = re.compile('[^a-z0-9-_.]')
    new_id = p.sub('',new_id)
    p = re.compile('[.]{2,}')
    new_id = p.sub('.',new_id)
    p = re.compile('^[.]|[.]$')
    new_id = p.sub('',new_id)
    
    new_id = 'a' if len(new_id) == 0 else new_id[0:15]
    new_id = p.sub('',new_id)
    if len(new_id) <= 2:
        c = new_id[len(new_id)-1]
        while len(new_id) < 3:
            new_id += c
            
    return new_id
