T = int(input())
def swap(list_,x,y):
    tmp=list_[x]
    list_[x] = list_[y]
    list_[y] = tmp
    return list_

def dfs_num(n,k):
    global comb,flag,case,num
    
    if n == 2:
        x=case.copy()
        comb.append(x)
        return
    for i in range(k,len(num)):
        case.append(i)
        dfs_num(n+1,i+1)
        case.pop()
        
def dfs_comb(n):
    global comb,all_case,num,max_
    if n == cnt:
        cop = num.copy()
        
        print(case)
        for i in range(cnt):
            x,y=case[i]
            cop = swap(cop,x,y)
        aa=int(''.join(cop))
        if max_ < aa:
            max_=aa
        return
    for i in range(len(comb)):
        case.append(comb[i])
        dfs_comb(n+1)
        case.pop()
        
        
for _ in range(1,T+1):
    max_=0
    all_case=[]
    case = []
    comb=[]
    num,cnt = list(map(int,input().split()))
    num = list(str(num))
    dfs_num(0,0)
    print(comb)
    case=[]
    dfs_comb(0)
    print('#'+str(_),max_)
