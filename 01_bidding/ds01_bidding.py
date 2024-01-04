n = int(input())
saram = []
orignnum = []
sortnum = []
cnt = []
for _ in range(n): #사람리스트, 돈리스트에 데이터 넣기
    a,b= input().split()
    b=int(b)
    saram.append(a)

    if b not in sortnum:
        sortnum.append(b)
        cnt.append(1)
    else:
        idx = sortnum.index(b)
        cnt[idx] += 1

    orignnum.append(b)

for i,w in enumerate(cnt):
    if(w!=1):
        sortnum[i]=0 #임의값
maxnum = max(sortnum)
if(maxnum == 0):
    print("NONE")
else:
    sol_idx = orignnum.index(maxnum)
    print(saram[sol_idx])



