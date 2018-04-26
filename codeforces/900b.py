from decimal import *
getcontext().prec = 1000000
r = list(map(int, input().split()))
a=r[0]
b=r[1]
c=r[2]
t = Decimal(a)/Decimal(b)
t = str(t)+"00"
ans = -1
gg=0
for i in range(len(t)):
	if gg == 0:
		if t[i]=='.':
			gg=1
		continue
	if ord(t[i])-ord('0') == c:
		ans = i
		break
if ans  == 1000001 or ans < 0:
	print(-1)
else:
	rr = int(a/b)
	rr = str(rr);
	#print("rr", rr)
	#print(ans, t)
	print(ans - len(rr))