from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Safari(executable_path = '/usr/bin/safaridriver')
driver.get('https://en.wikipedia.org/wiki/Pok%C3%A9mon_Horizons:_The_Series')
someTxt = driver.find_elements(By.CLASS_NAME, "shortSummaryText")
for r in someTxt:
    print(r.text)
driver.close()
