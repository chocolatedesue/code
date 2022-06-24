n = int(input())
List = list(map(int,input().split()))
#洛谷 多项式输出
#模拟题， 分类matter 多条件if有奇效
for i in range(n,-1,-1):
    if (List[n-i]):
        if (i!=n and List[n-i]>0):
            print ("+",end="")
        if (abs(List[n-i])>1 or i==0):
            print (List[n-i],end="")
        if (List[n-i]==-1 and i!=0):
            print ("-",end="")
        if (i>1):
            print (f"x^{i}",end="")
        if (i==1):
            print ("x",end="")