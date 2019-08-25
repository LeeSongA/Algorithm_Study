T = int(input())
def sum_list(tmp):
    sum_ = 0
    for i in range(len(tmp)):
        sum_+=tmp[i]
    return sum_

for _ in range(1,T+1):
    N,K = list(map(int,input().split()))
    group = [[] for i in range(K+1)]
    for i in range(N):
        for j in range(1,K+1):
            if i%2 == 0:
                group[j].append(i*K+j)
            else:
                
                group[K-j+1].append(i*K+j)
    print('#'+str(_),end=' ')
    for i in range(1,len(group)):
        print(sum_list(group[i]),end=' ')
    print()
            
