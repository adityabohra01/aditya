import time
# print(time)
# print(dir(time))
sec = time.time()
print(sec)
print(time.time())
var = time.ctime(sec)
print(var)
print("now")
time.sleep(5)
print("after 5 sec")

res = time.localtime(sec)
print(res)
