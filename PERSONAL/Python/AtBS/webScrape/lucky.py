#! python3
# This program will open several Google results

import requests
import sys
import webbrowser
import bs4

# Front-end text to show user
print('Googling...')

# Search Google using whatever the user passed in the command line
res = requests.get('http://google.com/search?q=' + ''.join(sys.argv[1:]))

# Safety check: did the requests return anything
res.raise_for_status()

# Make an object containing all of the HTML in the request
soup = bs4.BeautifulSoup(res.text)

# Scrape the links from the request
linkElems = soup.select('.r a')

# Set the number of tabs to be opened
numOpen = min(5, len(linkElems))

# Iterate through the first 5 links and open them
for i in range(numOpen):
    webbrowser.open('http://google.com' + linkElems[i].get('href'))
