import sys

N = int(sys.stdin.readline())
for i in range(1,N+1):
    num = list(map(int,sys.stdin.readline().split()))
    print(f"Case #{i}: {num[0]} + {num[1]} =",sum(num))