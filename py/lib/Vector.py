#https://www.tutorialspoint.com/python/python_classes_objects.htm

class Vector:
   def __init__(self, a, b):
      self.a = a
      self.b = b

   def __str__(self):
      return 'Vector (%d, %d)' % (self.a, self.b)

   def __add__(self,other):
      return Vector(self.a + other.a, self.b + other.b)

def show(str):
   print str

#python
#>>> import Vector          #ModuleName:Vector ClassName:Vector
#>>> v1=Vector.Vector(7,8)  #ModuleName.ClassName
#>>> v2=Vector.Vector(1,2)
#>>> v3=v1+v2
#>>> print v3
#>>> Vector (8, 11)

#>>> Vector.show("You're using Python 2.7.12") #ModuleName.FunctionName
