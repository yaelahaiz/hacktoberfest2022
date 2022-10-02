import multiprocessing 
import requests
import time
import re
t = time.localtime()
current_time = time.strftime("%H:%M:%S", t)
 
 
def gas(auth):
  while(True):
      headers = {"authorization": auth}
      url = 'http://kitkabackend.eastus.cloudapp.azure.com:5010/round/finishv2/3'
      response = requests.get(url, headers=headers)
      text = response.text
      if '{"User":{"Id"' in text:
          getnick = re.search('"Username":"(.+?)","Country"', text)
          if getnick:
              nick = getnick.group(1)
          gettrophy = re.search('"HiddenRating":(.+?),"IsBanned', text)
          if gettrophy:
              trophy = gettrophy.group(1)
          getcrown = re.search('"Crowns":(.+?),"HiddenRating"', text)
          if getcrown:
              crown = getcrown.group(1)
 
          print("[" + current_time + "] " + "Nick : " + nick + " | Trophy : " + trophy + " | Crowns : " + crown)
      else:
          print("Cookie Salah")
          exit()
 
 
 
if __name__ == "__main__":
    auth = input('Cookie : ')
    worker = int(input("Berapa Thread : "))
    for _ in range(worker):
        p = multiprocessing.Process(target=gas, args=[auth])
        p.start()
