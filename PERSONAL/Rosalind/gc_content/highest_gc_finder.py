# READ TEXT DATABASE FROM A FILE
dnadict = {}
idlist = []
dnaid = ''
dnastring = ''
nlidx = 0
print('READING IN DATA')
with open('input.txt', 'r') as dnafile:
    lines = dnafile.readlines()
    for line in lines:
        for i in range(len(line)):
            if line[i] == '>':
                idlist = [line]
print(idlist)
      
            
        
    
  
# STORE ID:DNA KEY:VALUE
# CALC GC FOR ALL DNA STRINGS
# COMPARE GC OF ALL DNA STRINGS
# RETURN HIGHEST GC ID AND PERCENTAGE

print(dnadict)
#print(lines)
#print(string)
