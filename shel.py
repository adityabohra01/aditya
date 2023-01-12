# import shelve
# shelFile = shelve.open('mydata')
# player = ['Virat','Dhoni','Yuvraj']
# shelFile['player'] = player
# shelFile.close()
# shelFile = shelve.open('mydata')
# print(shelFile['player'])

import shutil

# shutil.copy('/Users/kritibohra/mess.txt','/Users/kritibohra/test')
#shutil.copy('/Users/kritibohra/mess.txt','/Users/kritibohra/test/test.py') #Overrides

#shutil.copytree('/Users/kritibohra/test','/Users/kritibohra/test1')

shutil.move('/Users/kritibohra/shel.py','/Users/kritibohra/aditya')
shutil.move('/Users/kritibohra/class2.py','/Users/kritibohra/aditya')