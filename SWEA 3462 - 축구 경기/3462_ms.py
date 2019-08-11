T = int(input())
aa=[0,1,4,6,8,9,10,12,14,15,16,18,20,21,22,24,25,26,27,28,30]

def sum_list(tmp):
    summ=0
    for i in range(len(tmp)):
        summ += tmp[i]
    return summ

for _ in range(1,T+1):
    percentage = 0
    
    A,B = list(map(int,input().split()))
    per_A = []
    per_B = []
    for i in range(31):
        perA=1
        perB=1
        comb = 1
        if i in aa:
            for j in range(30-i):
                perA *= 1-(A/100)
                perB *= 1-(B/100)
            for j in range(i):
                perA = (perA * A/100)
                perB = (perB * B/100)
                comb*=(30-j)/(j+1)
            per_A.append(perA*comb)
            per_B.append(perB*comb)
            
    #sum_A = sum_list(per_A)
    sum_B = sum_list(per_B)
    #print(sum_A,sum_B)
    for i in range(len(per_A)):
        percentage += per_A[i] * sum_B
    
        
    print('#'+str(_),'{0:.5}'.format(1-percentage))
