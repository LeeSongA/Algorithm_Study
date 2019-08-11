T = int(input())
for _ in range(1,T+1):
    cnt = 0
    ccc=0
    TC=list(input())
    for i in range(len(TC)):
        if TC[i] == '(':
            if TC[i+1] == '(':
                ccc+=1
            elif TC[i+1] == ')':
                cnt += ccc
                
        if TC[i] == ')':
            if TC[i-1] != '(':
                cnt +=1
                ccc -=1
    print('#'+str(_),cnt)
    
