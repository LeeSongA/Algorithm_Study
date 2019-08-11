T = int(input())
dir_x=[1,0,-1,0]
dir_y=[0,1,0,-1]
def bfs_cost(n):
    global mapping,visit, max_score,cost
    
    que = []
    
    for i in range(N):
        for j in range(N):
            score = 0
            que.append([i,j])
            for xxx in range(cost):
                
                if que == []:
                    continue
                x,y = que.pop(0)
                visit[x][y] = 1
                for j in range(4):
                    if x+dir_x[j]>=0 and y+dir_y[j]>=0 and x+dir_x[j]<N and y+dir_y[j]<N and visit[x+dir_x[j]][y+dir_y[j]]==0:
                        que.append([x+dir_x[j],y+dir_y[j]])
                        
                        if mapping[x+dir_x[j]][y+dir_y[j]] == 1:
                            score+=1
            
            visit = [[0]*N for xxxxxxx in range(N)]
            if max_score < score and (score*M) > cost:
                max_score = score
                print(score,cost)
                
                        
for _ in range(1,T+1):
    max_score=0
    mapping=[]
    
    N,M =list(map(int, input().split()))
    visit = [[0]*N for i in range(N)]
    
    for i in range(N):
        map_ = list(map(int, input().split()))
        mapping.append(map_)
    for i in range(1,N+2):
        
        cost = i*i-(i-1)*(i-1)
        bfs_cost(i)
    print(max_score)
