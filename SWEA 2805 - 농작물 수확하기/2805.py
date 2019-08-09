T = int(input())

def farming():
    global mapping,cnt,test
    
    for i in range(int(N/2)+1):
        for j in range(2*i+1):
            cnt += mapping[i][(int(N/2)-i)+j]
            
       
    for i in range(int(N/2)+1,N):
        for j in range(2*(N-i-1)+1):
            cnt += mapping[i][(int(N/2)-(N-i))+j+1]
            
            
for _ in range(1,T+1):
    cnt = 0
    mapping=[]
    N = int(input())
    test = [[0]*N for _ in range(N)]
    for i in range(N):
        map_ = list(map(int,input()))
        mapping.append(map_)
    farming()
    print('#'+str(_),cnt)
    '''
    for i in range(N):
        print(test[i])
'''
