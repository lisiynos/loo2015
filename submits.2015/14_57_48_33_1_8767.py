with open('hall.in', 'r') as infile:
    a, b, c, d = [int(x) for x in infile.readline().split()]
hall_counter = 0
for x in range(1, b + 1):
    for y in range(1, b + 1):
        if c <= (x + y) * 2  <= d and a <= x * y <= b:
            hall_counter += 1
hall_counter = str(int((hall_counter + 1)/2))
with open('hall.out', 'w') as outfile:
    outfile.write(hall_counter)