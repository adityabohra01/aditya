import bs4
import requests

# res = requests.get('https://nostartch.com')
# print(res.raise_for_status())

# bsobj = bs4.BeautifulSoup(res.text, 'html.parser')
# print(type(bsobj))
# print(bsobj)

# file = open('/Users/kritibohra/aditya/test.html')
# bsobj = bs4.BeautifulSoup(file, 'html.parser')
# print(type(bsobj))
# print(bsobj)

# exfile = open('/Users/kritibohra/aditya/test.html')
# exfile = open('/Users/kritibohra/aditya/test.html')
# exbsoup = bs4.BeautifulSoup(exfile.read(), 'html.parser')
# elems = exbsoup.select('#author')
# print(type(elems))
# print(len(elems))
# print(elems[0])
# print(str(elems[0]))
# print(elems[0].getText())
# print(elems[0].attrs)

res = requests.get('https://www.rnsit.ac.in/')
soup = bs4.BeautifulSoup(res.text, 'html.parser')
elems = soup.select('.menu-item')
print(type(elems))
print(len(elems))
print(elems[0])
print(str(elems[0]))
print(elems[0].getText())
print(elems[0].attrs)



