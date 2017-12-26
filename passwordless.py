import urllib2
import urllib
import cookielib
def Brower(url):
    login_page = "http://10.129.32.105:9704/analytics/saw.dll?bieehome&startPage=1"
    login_data="NQUser=weblogic&NQPassword=biee123c0m&isCookieEnable=1&action=on&wrong_passwd=%3C%21--invalid_passwd_flag--%3E" #get from fiddler
    try:
        cj = cookielib.CookieJar()
        opener=urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
        opener.addheaders = [('User-agent','Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0; .NET CLR 2.0.50727; .NET CLR 3.0.4506.2152; .NET CLR 3.5.30729; MS-RTC LM 8; InfoPath.2; CIBA; .NET4.0C; .NET4.0E; .NET CLR 1.1.4322)')]

        opener.open(login_page,login_data)
        op=opener.open(url)
        data= op.read()
        return data
    except Exception,e:
        print str(e)
print Brower("http://10.129.32.105:9704/analytics/saw.dll?bieehome&startPage=1")  #the URL you want to browser
