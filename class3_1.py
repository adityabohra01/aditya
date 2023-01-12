class point:
    '''This represents point'''
obj=point()
obj.x=3.0
obj.y=5.0
import copy
obj_copy=copy.copy(obj)
def prnt(obj):
    print(obj.x,obj.y)
prnt(obj_copy)
print(obj_copy is obj)
obj_copy1=obj
print(obj_copy1 is obj)


