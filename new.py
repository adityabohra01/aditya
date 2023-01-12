class Time :
    '''Attribute hour minutes second'''

def time_to_int(time):
    min = time.hour * 60 + time.minutes
    sec = min * 60 + time.second
    return sec

def int_to_time(sec):
    time = Time()
    min, time.second = divmod(sec, 60)
    time.hour, time.minutes = divmod(min, 60)
    return time

def add_time(t1, t2):
    sec = time_to_int(t1) + time_to_int(t2)
    return int_to_time(sec)

def print_time(t):
    print('%.2d hours:%.2d min:%.2d sec' % (t.hour, t.minutes, t.second))

t1 = Time()
t1.hour = 1
t1.minutes = 2
t1.second = 3

t2 = Time()
t2.hour = 4
t2.minutes = 5
t2.second = 6

print_time(t1)
print_time(t2)
print_time(add_time(t1,t2))

print(type(divmod(16,4)))