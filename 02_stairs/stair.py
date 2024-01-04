sunbun = list(map(int,input().split()))
sblen = len(sunbun)-1
xjum = [0]
yjum = [0]

xsum = 0
ysum = 0
for i in range(sblen):
    if(i%2):
        ysum += sunbun[sblen-i]
        for _ in range(2):
            yjum.append(ysum)
    else:
        xsum += sunbun[i];
        for _ in range(2):
            xjum.append(xsum)
yjum.reverse()

while(1):
    try:
        x,y=map(int,input().split())
        for k,w in enumerate(xjum):
            if w>x:
                if y>yjum[k]:
                    print("out")
                elif y==yjum[k]:
                    print("on")
                else:
                    print("in")
                break

            elif w==x:
                if y>yjum[k]:
                    print("out")
                elif yjum[k+1]<=y<=yjum[k]:
                    print("on")
                else:
                    print("in")
                break
        if(w<x):
            print("out")
    except :
            break

