H,M = map(int,input().split())
addmint = int(input())

M += addmint

if M >= 60:
    H += (M//60)
    M = (M%60)
if H > 23:
    H -= 24

print(H,M)