import shutil

def ren(f,t):
  print f,'=>',t
  shutil.move(f, t)

shift = 3
for i in range(48,0,-1):
  inFile = "%02d" % i
  outFile = "%02d.a" % i
  inFile2 = "%02d" % (i+shift)
  outFile2 = "%02d.a" % (i+shift)
  ren(inFile,inFile2)
  ren(outFile,outFile2)

  
