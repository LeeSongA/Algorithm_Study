dir_x = [1,0,-1,0]
dir_y = [0,1,0,-1]

T = int(input())

def bfs(que):
    global max_index,max_cnt,mapping
    cnt = 0
    start = que[0][0]
    while que != []:
        cnt += 1
        num,y,x=que.pop(0)
        for i in range(4):
            if y+dir_y[i] >= 0 and y+dir_y[i] < N and x+dir_x[i] >= 0 and x+dir_x[i] < N and mapping[y+dir_y[i]][x+dir_x[i]] == num +1:
                que.append([mapping[y+dir_y[i]][x+dir_x[i]],y+dir_y[i],x+dir_x[i]])
    if cnt > max_cnt:
        max_cnt = cnt
        max_index = start
    elif cnt == max_cnt:
        if max_index > start:
            max_index = start
def maxmax():
    global max_index,max_cnt,mapping
    que = []
    for i in range(N):
        for j in range(N):
            que.append([mapping[j][i],j,i])
            bfs(que)

for _ in range(1,T+1):
    mapping=[]
    max_index = 0
    max_cnt = 0
    
    N=int(input())
    for i in range(N):
        map_ = list(map(int,input().split()))
        mapping.append(map_)
    maxmax()
    print('#'+str(_),max_index,max_cnt)
