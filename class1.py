#that represents string representation of the object def __str__
class time:
        def __init__(self,hours = 0, minute = 0 ,seconds = 0):
            self.hours = hours
            self.minute = minute
            self.seconds = seconds

        def time_to_int(time):
            min = time.hour * 60 + time.minutes
            sec = min * 60 + time.second
            return sec

        def print_time(self):
            print("%.2d : %.2d : %.2d" %(self.hours,self.minute,self.seconds))
        def __str__(self):
            return "%.2d : %.2d : %.2d" %(self.hours,self.minute,self.seconds)
start = time()
start.print_time()
test = time(10,20,30)
test.print_time()
print(test)



