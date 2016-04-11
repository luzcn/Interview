import urllib.request
url = "http://www.google.com/"
request = urllib.request.Request(url)
response = urllib.request.urlopen(request)
print (response.read())