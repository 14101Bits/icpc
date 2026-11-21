N = int(input())
a = list(map(int, input().split()))

bits = [0] * 100

for i in range(N):
    bit = a[i]
    bits[bit-1] = (bits[bit-1] + 1) % 2

sum = 0
for i in range(100):
    sum += (i+1) * bits[i]

print(sum)