class time:
    '''attributes: hour, minute, second'''
obj=time()
obj.hour=10
obj.minute=20
obj.second=30
def print_time(obj):
    print("%.2d:%.2d:%.2d"%(obj.hour,obj.minute,obj.second))
print_time(obj)
def addTime(t1,t2):
    sum=time()
    sum.second=0 
    sum.minute=0
    sum.hour=0
    sum.second=t1.second+t2.second
    if(sum.second>=60):
        sum.minute+=1
        sum.second-=60
    sum.minute+=t1.minute+t2.minute
    if(sum.minute>=60):
        sum.hour+=1
        sum.minute-=60
    sum.hour+=t1.hour+t2.hour
    return sum
obj2=time()
obj2.hour=10
obj2.minute=20
obj2.second=30
obj3=addTime(obj,obj2)
print_time(obj3)


