def sorting(l):
    temp=0
    for _ in range(len(l)):
        for i in range(len(l)-1):
            if l[i]>l[i+1]:
                a,b=l[i],l[i+1]
                l[i],l[i+1]=b,a
    return l
lis=[5,4,3,6,8,1,0,-8,-4,2,-6]
print(sorting(lis))
