class rectangle:
    '''represent a rectangle
    attributes: width, height,corner'''

class point:
    '''This represents point'''

box=rectangle()
box.width=3.5
box.height=2.0
box.corner=point()
box.corner.x=3.0
box.corner.y=5.0
#Box.corner refers to the point object
#and go to the x and y attributes of the point object.
def find_center(rect):
    p=point()
    p.x=rect.corner.x+rect.width/2.0
    p.y=rect.corner.y+rect.height/2.0
    return p
centre=find_center(box)
print(centre.x,centre.y)
#Objects are mutable

def grow_rect(rect,dwidth,dheight):
    rect.width+=dwidth
    rect.height+=dheight
grow_rect(box,100,200)
print(box.width,box.height)

#check graph is cyclic or not

# Path: class4.py
class graph:
    def __init__(self):
        self.vertices={}
    def add_vertex(self,vertex):
        if vertex not in self.vertices:
            self.vertices[vertex]=[]
    def add_edge(self,vertex1,vertex2):
        if vertex1 in self.vertices and vertex2 in self.vertices:
            self.vertices[vertex1].append(vertex2)
            self.vertices[vertex2].append(vertex1)
    def __str__(self):
        return str(self.vertices)
    def is_cyclic(self):
        visited={}
        for vertex in self.vertices:
            visited[vertex]=False
        for vertex in self.vertices:
            if visited[vertex]==False:
                if self.is_cyclic_util(vertex,visited,-1)==True:
                    return True
        return False
    def is_cyclic_util(self,vertex,visited,parent):
        visited[vertex]=True
        for i in self.vertices[vertex]:
            if visited[i]==False:
                if self.is_cyclic_util(i,visited,vertex)==True:
                    return True
            elif i!=parent:
                return True
        return False    