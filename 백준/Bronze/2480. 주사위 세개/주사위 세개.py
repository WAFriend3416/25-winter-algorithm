num = list(map(int,input().split()))

if(num[0] == num[1] and num[1] == num[2]):
    print(num[0]*1000 + 10000)
elif(num[0] == num[1] and num[1] != num[2]):
    print(num[0]*100 + 1000)
elif(num[0] != num[1] and num[1] == num[2]):
    print(num[1]*100 + 1000)
elif(num[0] == num[2] and num[1] != num[2]):
    print(num[2]*100 + 1000)
else:
    print(max(num)*100)