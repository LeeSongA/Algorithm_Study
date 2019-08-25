pipe = ['|','-','+','1','2','3','4','.','Z','M']
pipe_dir=[[1,0,1,0],[0,1,0,1],[1,1,1,1],[0,0,1,1],[1,0,0,1],[1,1,0,0],[0,1,1,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]
dx = [0,-1,0,1]
dy = [-1,0,1,0]


def bfs(y,x):
    global mapping,visit
    visit[y][x] = 1
    que = []
    for i in range(4):
        sx = x+dx[i]
        sy = y+dy[i]
        if sx < 0 or sy < 0 or sx >=C or sy >= R:
            continue
        if mapping[sy][sx] != '.':
            que.append([sy,sx])
            visit[sy][sx] = 1
        
    while que != []:
        y,x = que.pop(0)
        for i in range(4):
            if pipe_dir[pipe.index(mapping[y][x])][i] == 0:
                continue
            nx = x+dx[i]
            ny = y+dy[i]
            if nx < 0 or ny < 0 or nx >=C or ny >= R:
                continue
            if visit[ny][nx] ==1:
                continue
            if mapping[ny][nx] == '.':
                return [ny,nx]
            que.append([ny,nx])
            visit[ny][nx] = 1
            
def find_pipe(y,x):
    global mapping
    ref = [0,0,0,0]
    for i in range(4):
        
        nx = x+dx[i]
        ny = y+dy[i]
        
        if nx < 0 or ny < 0 or nx >=C or ny >= R:
            
            continue
        
        
       
        ref[i] = pipe_dir[pipe.index(mapping[ny][nx])][(i+2)%4]
    
    return pipe[pipe_dir.index(ref)]
mapping =[]    
R,C =list(map(int, input().split()))
for i in range(R):
    visit = [[0]*C for ppp in range(R)]
    map_=list(map(str, input()))
    mapping.append(map_)

for j in range(R):
    for i in range(C):
        
        if mapping[j][i] == 'M':
            by,bx= bfs(j,i)
            pipe_select=find_pipe(by,bx)
            print(by+1,bx+1,pipe_select)
