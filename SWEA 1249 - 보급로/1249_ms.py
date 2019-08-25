dx = [1,0,-1,0]
dy = [0,-1,0,1]
T = int(input())
def bfs():
    global dist, mapping
    que=[]
    que.append([0,0,0])
    dist[0][0] = 0
    while que!=[]:
        x,y,t=que.pop(0)
        #if x==N-1 and y ==N-1:
        #    break
        if dist[x][y] < t:
            continue
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx<0 or ny <0 or nx>=N or ny>=N:
                continue
            
            if(mapping[nx][ny]>0):
                
                if dist[nx][ny] > dist[x][y] + mapping[nx][ny]:
                    que.append([nx,ny,t+mapping[nx][ny]])
                    dist[nx][ny] = dist[x][y] + mapping[nx][ny]
            else:
                if dist[nx][ny] > dist[x][y]:
                    que.append([nx,ny,t])
                    dist[nx][ny] = dist[x][y]
    return dist[N-1][N-1]

for _ in range(1,T+1):
    mapping=[]
    N = int(input())
    dist = [[999]*N for ppp in range(N)]
    for i in range(N):
        
        map_=list(map(int, input()))
        mapping.append(map_)
            
    print('#'+str(_),bfs())
