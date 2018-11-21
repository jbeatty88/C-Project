#! python3
# Downloads every single XKCD comic

import requests, os, bs4, threading

# XKCD Url to get comics from
url = 'http://xkcd.com'

def downloadXkcd(sComic, eComic):
    # Iterate through all of the urls in a range
    for urlNnumber in range(sComic, eComic + 1):
        # Front-end message
        print('Loading page http://xkcd.com/%s...' % (urlNumber))
        # Make a request to XKCD site and store response
        res = requests.get('http://xkcd.com/%s' % (urlNnumber))
        # Make sure it actually returned something
        res.raise_for_status()
        # Store the response as parsable HTML
        soup.bs4.BeautifulSoup(res.text)
        # Select the correct HTML tag to get the download link
        comicElem = soup.select('$comic img')
        # If there is no link
        if comicElem == []:
            # Print an error description
            print('Could not find comic image.')
        # If there is a link
        else:
            # Get the first src value
            comicUrl = comicElem[0].get('src')
            # Front-end message
            print('Dowloading img %s...' % (comicUrl))
            # Make sure that the response is still good
            res.raise_for_status()
            # Make a directory to store the images
            imageFile = open(os.path.join('xkcd', os.path.basename(comicUrl)), 'wb')
            # Iterate through the chunk of data
            for chunk in res.iter_content(100000):
                # Write to local dir
                imageFile.write(chunk)
            # Close file
            imageFile.close()

downloadThreads = []
# Iterate through range of 1 to 1400 by 100's
for i in range(0, 1400, 100):
    # Make a thread
    downloadThread = threading.Thread(target=downloadXkcd, args=(i, i+99))
    # Add it to the list of threads
    downloadThreads.append(downloadThread)
    # Start the thread
    downloadThread.start()

# Make a new directory to store the comics
os.makedirs('xkcd', exist_ok=True)
# Get comics until the href value in html is # meaning no more
while not url.endswith('#'):
    print('Downloading page %s...' % url)

    # Get all of the data from the url
    res = requests.get(url)
    # Make sure our request returned something
    res.raise_for_status()
    # Save the data from the request as parsable HTML object
    soup = bs4.BeautifulSoup(res.text)
    # Select the img tag
    comicElem = soup.select('#comic img')
    # If there was no img tag
    if comicElem == []:
        # Print this message
        print('Could not find comic image')
    # If there was an img tag
    else:
        try:
            # using the img tag, get the img src and add it to url
            comicUrl = 'http:' + comicElem[0].get('src')
            # Front-end message
            print('Downloading image %s...' % (comicUrl))
            # Make a new request for that specific img
            res = requests.get(comicUrl)
            # make sure that it returns something
            res.raise_for_status()
        # If we catch an exception
        except requests.exceptions.MissingSchema:
            # select the previous link
            prevLink = soup.select('a[rel="prev"]')[0]
            # update the url
            url = 'http://xkcd.com' + prevLink.get('href')
            continue
        # As we get img data, get ready to store it locally
        imgFile = open(os.path.join('xkcd', os.path.basename(comicUrl)), 'wb')
        # Iterate through our img data and gather it in chunks
        for chunk in res.iter_content(100000):
            # Save it to harddrive
            imgFile.write(chunk)
        # close file
        imgFile.close()

        prevLink = soup.select('a[rel="prev"]')[0]
        url = 'http://xkcd.com' + prevLink.get('href')

        for downloadThread in downloadThreads:
            downloadThread.join()
        print('Done')
    
