import sys
import os
import numpy as np

### BASIC ERROR HANDLES FOR IMPROPER INPUT ###
#        If not enough arguments given       #
if len(sys.argv) != 2:
    print('USAGE: python3.6 py_file.py in_file.txt')
    sys.exit(1) # 1 signifies error

#        If file is invalid                  #
if not os.path.exists(sys.argv[1]):
    print('ERROR: %s DOES NOT EXIST' % (sys.argv[1]))
    sys.exit(1)

# Store argument given (filename) in a variable
input_file = sys.argv[1]

#     DNA class for better data management    #
class Dna:
    def __init__(self):
        self.r_id = ''
        self.dna_string = ''
        self.gc_string = ''
        self.gc_content = 0

    # CALCULATE GC CONTENT
    def calculate_gc(self):
        gc_arr = np.array([])
        # Measure dna_string
        dna_string_len = int(len(self.dna_string))
        # Copy ONLY GC from dna string
        for i in range(dna_string_len):
            if self.dna_string[i] == 'G' or self.dna_string[i] == 'C':
                gc_arr = np.append(gc_arr, self.dna_string[i])
            self.gc_string = ''.join(gc_arr)
            
        # Measure gc_string
        gc_string_len = int(len(self.gc_string))
        
        # Divide gc_string measurement by dna_string
        self.gc_content = (gc_string_len/dna_string_len) * 100
        # Store in gc_content
        
        

def get_data(filename):
    dna_arr = np.array([])
    count = 0
    # OPEN FILE & READ IN DATA
    print('Opening file: %s' % (filename))
    with open(filename, 'r') as dna_data:
        # SORT/STORE DATA
        all_data = dna_data.readlines()
        for line in all_data:
            # Split will get rid of the newlines \n
            vals = line.split()
            # Append the \n-free values to a numpy array
            dna_arr = np.append(dna_arr, vals)
        #for x in np.nditer(dna_arr):
        #    print(x)
        print(len(dna_arr))
        # Every ID has 2 lines of DNA ---> Divide total size by 3 to get ID count
        count = int(len(dna_arr) / 18) # FIXME: NON EQUAL DNA STRAND LENGTHS
        # Dynamically creates an class object based on count of ID's
        strands = [Dna() for _ in range(count)]
        for i in range(count):     
            if i == 0:
                strands[i].r_id = dna_arr[i * count]
                strands[i].dna_string = ''.join(
                    dna_arr[(i * count) + 1] + dna_arr[(i * count) + 2]
                    + dna_arr[(i * count) + 3] + dna_arr[(i * count) + 4]
                    + dna_arr[(i * count) + 5] + dna_arr[(i * count) + 6]
                    + dna_arr[(i * count) + 7] + dna_arr[(i * count) + 8]
                    + dna_arr[(i * count) + 9] + dna_arr[(i * count) + 10]
                    + dna_arr[(i * count) + 11] + dna_arr[(i * count) + 12]
                    + dna_arr[(i * count) + 13] + dna_arr[(i * count) + 14]
                    + dna_arr[(i * count) + 15] + dna_arr[(i * count) + 16]
                    + dna_arr[(i * count) + 17] 
                )
            if i == 1:
                strands[i].r_id = dna_arr[i * count]
                strands[i].dna_string = ''.join(
                    dna_arr[((i * count) + 1)] + dna_arr[(i * count) + 2]
                    + dna_arr[(i * count) + 3] + dna_arr[(i * count) + 4]                 
                    + dna_arr[(i * count) + 5] + dna_arr[(i * count) + 6]                             
                    + dna_arr[(i * count) + 7] + dna_arr[(i * count) + 8]                          
                    + dna_arr[(i * count) + 9] + dna_arr[(i * count) + 10]                            
                    + dna_arr[(i * count) + 11] + dna_arr[(i * count) + 12]                          
                    + dna_arr[(i * count) + 13] + dna_arr[(i * count) + 14]                      
                    + dna_arr[(i * count) + 15] + dna_arr[(i * count) + 16]                          
                   
                )
            if i == 2:
                strands[i].r_id = dna_arr[i * count]
                strands[i].dna_string = ''.join(                                                                                                                                                                  
                    dna_arr[((i * count) + 1)] + dna_arr[(i * count) + 2]                                                                                                                                         
                    + dna_arr[(i * count) + 3] + dna_arr[(i * count) + 4]                                                                                                                                         
                    + dna_arr[(i * count) + 5] + dna_arr[(i * count) + 6]                                                                                                                                         
                    + dna_arr[(i * count) + 7] + dna_arr[(i * count) + 8]                                                                                                                                         
                    + dna_arr[(i * count) + 9] + dna_arr[(i * count) + 10]                                                                                                                                        
                    + dna_arr[(i * count) + 11] + dna_arr[(i * count) + 12]                                                                                                                                       
                    + dna_arr[(i * count) + 13] + dna_arr[(i * count) + 14]                                                                                                                                       
                    + dna_arr[(i * count) + 15]                                                                                                                                
                   
                )                                   
            if i == 3:
                strands[i].r_id = dna_arr[i * count]
                strands[i].dna_string = ''.join(                                                                                                                                                                  
                    dna_arr[((i * count) + 1)] + dna_arr[(i * count) + 2]                                                                                                                                         
                    + dna_arr[(i * count) + 3] + dna_arr[(i * count) + 4]                                                                                                                                         
                    + dna_arr[(i * count) + 5] + dna_arr[(i * count) + 6]                                                                                                                                         
                    + dna_arr[(i * count) + 7] + dna_arr[(i * count) + 8]                                                                                                                                         
                    + dna_arr[(i * count) + 9] + dna_arr[(i * count) + 10]                                                                                                                                        
                    + dna_arr[(i * count) + 11] + dna_arr[(i * count) + 12]                                                                                                                                       
                    + dna_arr[(i * count) + 13] + dna_arr[(i * count) + 14]                                                                                                                                                                   
                )                                   
            if i == 4:
                strands[i].r_id = dna_arr[i * count]
                strands[i].dna_string = ''.join(                                                                                                                                                                  
                    dna_arr[((i * count) + 1)] + dna_arr[(i * count) + 2]                                                                                                                                         
                    + dna_arr[(i * count) + 3] + dna_arr[(i * count) + 4]                                                                                                                                         
                    + dna_arr[(i * count) + 5] + dna_arr[(i * count) + 6]                                                                                                                                         
                    + dna_arr[(i * count) + 7] + dna_arr[(i * count) + 8]                                                                                                                                         
                    + dna_arr[(i * count) + 9] + dna_arr[(i * count) + 10]                                                                                                                                        
                    + dna_arr[(i * count) + 11] + dna_arr[(i * count) + 12]                                                                                                                                       
                    + dna_arr[(i * count) + 13] + dna_arr[(i * count) + 14]                                                                                                                                       
                    + dna_arr[(i * count) + 15] + dna_arr[(i * count) + 16]                                                                                                                                       
                    + dna_arr[(i * count) + 17]                                                                                                                                                                   
                )                                   
                
    print('Closed file: %s' % (filename))
    print('Data Retrieved:')
    strands[0].calculate_gc()
    print(strands[0].r_id)
   # print(strands[0].dna_string)
   # print(strands[0].gc_string)
    print(str.format('{0:.6f}', strands[0].gc_content))
    
    strands[1].calculate_gc()
    print(strands[1].r_id)
   # print(strands[1].dna_string)
   # print(strands[1].gc_string)
    print(str.format('{0:.6f}', strands[1].gc_content))
    
    strands[2].calculate_gc()
    print(strands[2].r_id)
   # print( strands[2].dna_string)
   # print(strands[2].gc_string)
    print(str.format('{0:.6f}', strands[2].gc_content))
            
get_data(input_file)

# CALCULATE GC CONTENT


# COMPARE GC_CONTENTS

# RETURN LARGEST GC CONTENT

