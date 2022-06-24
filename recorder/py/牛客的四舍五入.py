'''
 important: 四舍五入规则，会将后续元素置为0

1. 可能不存在小数点
2. 贪心规则注意:
    1. 从左向右遍历，是5回退（防止有4）  不能从右往左 不符合t的遍历规则
3. 进位参考高精度 flatten
4. 细节处理 py的语法问题

'''


lens, t = map(int, input().split())
text = input()
try:
    idx = text.index(".")
except:
    print(text)
    exit(0)
    
flag=False
text = [int(i) for i in text if i >= "0" and i <= "9"]
if(t!=0):
    
    i=idx
    while i!=len(text) and t!=0:

        if text[i] >= 5:
            text[i-1] += 1
            text[i] = 0
            t -= 1
            text = text [:i+1:]
#            
            i-=1
            
        else:
            i+=1
            
        if (i<idx):
            break

        
for i in range(len(text)-1,0,-1):
    if (text[i]>=10):
        text[i]-=10
        text[i-1]+=1
    # print (i)

text.insert(idx,".")
while (text[-1]==0):
    text.pop()
if (text[-1]=="."):
    text.pop()
    
for i in text:
    print (i,end="")