import sys

N = int(sys.stdin.readline())
for _ in range(N):
    num = map(int,sys.stdin.readline().split())
    print(sum(num))