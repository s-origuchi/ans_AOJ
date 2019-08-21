import numpy as np

def get_input():
    depth = int(input())
    return depth


def koch_curve(p1, p2):
    point1 = np.array(p1)
    point2 = np.array(p2)
    dp=(point2-point1)/3
    
    point3=point1+dp
    point5=point1+dp*2

    rad60 = np.pi/3
    
    rotarray = np.array(((np.cos(rad60), -np.sin(rad60)),(np.sin(rad60),np.cos(rad60))))
    dp2 = rotarray*dp
    dp2 = dp2[:,0]+dp2[:,1]
    point4 = point3 + dp2

    return ([point3.tolist(), point4.tolist(), point5.tolist()])



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
