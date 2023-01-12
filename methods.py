# A method is self function that is associated with self particular class.
# Methods are functions that are defined inside self class and hence making the 
# relationship between the class and the function.

class Time:
    '''Attribute hour minutes second'''

    def print_time(self):
        print('%.2d hours:%.2d min:%.2d sec' % (self.hour, self.minutes, self.second))


t1 = Time()
t1.hour = 1
t1.minutes = 2
t1.second = 3

print(type(t1.print_time))
t1.print_time()
Time.print_time(t1)


#pass keyword in pyhton
#pass is a keyword in python that is used to define a block that does nothing.
#pass is used as a placeholder for future code.
#pass is also used for empty control statement, function or classes.





