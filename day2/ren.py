import shutil

def ren(f,t):
  print f,'=>',t
  shutil.move(f, t)

shift = 1
for i in range(41,0,-1):
  inFile = "%02d" % i
  outFile = "%02d.a" % i
  inFile2 = "%02d" % (i+shift)
  outFile2 = "%02d.a" % (i+shift)
  ren(inFile,inFile2)
  ren(outFile,outFile2)

  
