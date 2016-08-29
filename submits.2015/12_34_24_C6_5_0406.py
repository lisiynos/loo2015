f = open("circle.in")
s = f.read().split()
f.close()
n = int(s[0])
answer = n * (n - 1) / 2
if (n % 2 == 0):
    answer -= n / 2
f = open("circle.out", "w")
f.write(str(int(answer * 2)))
f.close()