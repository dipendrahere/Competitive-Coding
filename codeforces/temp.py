from decimal import *
getcontext().prec = 6
n,r = list(map(int, input().split()))
a = list(map(int, input().split()))
v = [[a[0], r]]
for i in range(1, n):
	y=r
	#print(i,":")
	for j in range(0, len(v)):
		#print("with ",j)
		if a[i]>=v[j][0]-r-r and a[i]<=v[j][0]+r+r:
			val  = v[j][1]
			rt = Decimal(Decimal(2.0)*Decimal(2.0)*Decimal(r)*Decimal(r) - Decimal(a[i] - v[j][0])*Decimal(a[i] - v[j][0]));
			#print("before ",rt)
			rt = rt.sqrt()
			#print("after ",rt)
			val =val+rt
			if val > y:
				y = val
	v.append([a[i], y])
for r in v:
	print(r[1],end=" ")