FIFO system，4个page，⼀一开始都没有load，先access100个不不同的page，按某个顺序，然后再反着 来。总共会有多少次page fault (196)

⼀一个⽆无向图，n个点，e个边，选择当图⽤用（1）邻接矩阵 O(n^2)（2）邻接列列表时DFS的时间复杂度。 O(n+3)

Single circular linked list, 有head和tail，需要加几个指针做到O(1) push和poll的queue，0

问下面这道的时间复杂度
if(n < 3)
    return 1;
else
    n = floor(sqrt(n));  loglogn

Telephone data structure, Graph

try-catch-finally，finally中有的

Queue using circular LL              答案 0

DFS in a graph                       答案 O(n^2)    O(n+e)

find the  output                          答案  4 errors

给出一个数据结构 能够支持string插入删除合并       答案 LL

Best data structure to manipulate a string with inserting, deleting: Linked list

circular linked list: 0 additional pointer

try, catch, final: final

找最大公约数：2437, 875 这个题目是1

postorder, preorder find inorder DBEAFCG

mystery algorithm         答案 1

'''

def mystreyAlg(a, b):
    x = a
    y = b
    while x != y:
        if x>y:
            x = x-y
        if x<y:
            y = y-x
    return x

print("################## mystreyAlg ########################")
print(mystreyAlg(2437, 875))

##########################################################################
'''

