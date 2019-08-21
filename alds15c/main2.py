import math

def get_input():
    depth = int(input())
    return depth


def koch_curve(p1, p2):
    dp=[(p2[0]-p1[0])/3, (p2[1]-p1[1])/3]
    
    point3=[p1[0]+dp[0], p1[1] + dp[1]]
    point5=[p1[0]+dp[0]*2, p1[1] + dp[1]*2]

    rad60 = math.pi/3
    dp2 = [dp[0]*math.cos(rad60)-dp[1]*math.sin(rad60), 
           dp[0]*math.sin(rad60)+dp[1]*math.cos(rad60)]
    

    point4=[point3[0]+dp2[0], point3[1] + dp2[1]]

    return ([point3, point4, point5])



def rec_koch_curve(pl, depth, target):
    if (target <= depth) :
        return
    
    for i in range(len(pl)-1)[::-1]:
        tplist = koch_curve(pl[i] , pl[i+1])
        for p in tplist[::-1]:
            pl.insert(i+1, p)

    rec_koch_curve(pl, depth+1, target)

def print_curve(pl):
    for p in pl:
        print(p[0],p[1],sep=" ")

pl = [[0,0],[100,0]]
rec_koch_curve(pl, 0, get_input())
print_curve(pl)
