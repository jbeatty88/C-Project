#!python3
# This app will launch a map in the browser using an address from the command line or the clipboard

import webbrowser
import sys
import pyperclip

if len(sys.argv) > 1:
    address = ''.join(sys.argv[1:])
else:
    address = pyperclip.paste()

webbrowser.open('https://www.google.com/maps/place/' + address)

print(address)
