from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
#from selenium.webdriver.support.ui import WebDriverWait
#from selenium.webdriver.support import expected_conditions as EC
import time

print("Automation has started")

PATH = "/usr/bin/safaridriver"
driver = webdriver.Safari(executable_path='/usr/bin/safaridriver')
session = 0
i = 1
while i < 2:
    driver.get("https://172.22.2.6/connect/")
    time.sleep(1)
    Username = driver.find_element(By.ID,'LoginUserPassword_auth_username')

    '''try: 
        Username = WebDriverWait(driver,10).until(EC.presence_of_all_elements_located(By.ID,'LoginUserPassword_auth_username'))
    except: 
        print("Username field not found"); driver.close();exit(0)'''

    Username.send_keys("20ucs138")
    Username.send_keys(Keys.RETURN)
    Password = driver.find_element(By.ID,'LoginUserPassword_auth_password')
    Password.send_keys("HfrS8797*")
    Password.send_keys(Keys.RETURN)
    session+=1
    print("Session no: " + str(session))
    j = 3
    while j > 0:
        print("     Hour no: "+str(4-j))
        time.sleep(3600)        
        driver.refresh()
        j-=1
    time.sleep(3480)
    #total sleep time = 14280 (3 hrs 58 mins)
    Logout = driver.find_element(By.ID,"UserCheck_Logoff_Button_span")
    Logout.click()
    time.sleep(1)

driver.close()
