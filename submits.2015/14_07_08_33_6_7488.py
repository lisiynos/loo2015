with open('forest.in', 'r') as infile:
    a, b, k, m, x = [int(x) for x in infile.readline().split()]
days = 0
while x > 0:
    days += 1
    if days % k != 0:
        x -= a
    if days % m != 0:
        x -= b
with open('forest.out', 'w') as outfile:
    outfile.write(str(days))
