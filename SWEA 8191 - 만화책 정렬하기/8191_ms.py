T = int(input())
for _ in range(1,T+1):
    N=int(input())
    sort =[]
    num = list(map(int,input().split())) 
    num_sort=num.copy()
    num_sort.sort()
    ans = 0
    rec = 1
    while sort != num_sort:
        
        
        for i in range(len(num)):
            print(num,i)
            if rec == num[i]:
                sort.append(num[i])
                num[i] = 0
                rec += 1
                
        ans +=1
    print(ans)
        
