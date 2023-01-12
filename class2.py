import os
file_name= open('mess.txt','w')
file_name.write('Hi this is a new file')
#After operating read or write operation on a file 
#perform close operaton before u open it.
file_name.close()
file_name = open('mess.txt','a')
file_name.write('\nHi file is modified')
file_name.close()






