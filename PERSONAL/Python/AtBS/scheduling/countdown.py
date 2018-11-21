#! python3
# This is a simple countdown program

import time, subprocess

# Get countdown number
timeLeft = input("How long to countdown?")

# While we haven't counted all the way down to 0
while timeLeft > 0:
    # Print the current value for time left until 0
    print(timeLeft, end='')
    # Pause for 1 second
    time.sleep(1)
    # Decrement time left unitl 0
    timeLeft = timeLeft - 1

# After the countdowns is finished, open this text file with a "End File" alert
subprocess.Popen(['see', 'endBreak.txt'])
