import sys

while(True):
    num1,num2 = map(int,sys.stdin.readline().split())
    sum_ = num1 + num2
    if sum_ == 0:
        break
    else:
        print(sum_)