n,y = map(int, input().split())

a = -1
b = -1
c = -1
for i in range(min(n, y//10000)+1):
  for j in range(min(n-i, (y-10000*i)//5000)+1):
    if ((n-i-j)*1000 == y-10000*i-5000*j):
      a = i
      b = j
      c = n-i-j

print(a, b, c)
