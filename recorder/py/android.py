dic={
    "1":[3,7,9],
    "2":[8],
    "3":[1,7,9],
    "4":[6],
    # ,"5":[1,2,3,4,5,6,7,8,9]
    "5":[]
    ,"6":[4],
    "7":[1,3,9],
    "8":[2]
    ,"9":[1,3,7]
}

# 安卓解锁  https://ac.nowcoder.com/acm/contest/19851/1002
# 打表判断路径  
# 核心 // / 的区别，条件如何判断

while True:
    s=""
    flag=True
    try:
        s=input()
    except:
        exit(0)
    lens = len(s)
    if (lens>9):
        print ("NO")
        continue
    else:
        mark=set()
        for i in range (lens-1):
            res = (int(s[i+1])+int(s[i]))//2
            if  (int(s[i+1]) in dic[s[i]] and str(res) not in mark ) :
                print("NO")
                flag=False
                break 
            elif s[i]==s[i+1]:
                print("NO")
                flag=False
                break 
            elif  s[i] in mark  or s[i+1] in mark:
                print("NO")
                flag=False
                break 
            else:
                mark.add(s[i])
        if (flag):
            print ("YES")
        