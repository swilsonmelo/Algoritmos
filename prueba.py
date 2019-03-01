"""
T(n)=5T(n-1)-6T(n-2)
x^2 +5x+ 6
(x-3)(x-2)
f(n)= A0(3^n)+A1(2^n)
f(0)=A0+A1
f(1)=3A0+2A1
f(0)=6; f(1)=12
6=A0+A1
12=3A0+2A1
A0=6-A1
12=3(6-A1)+2A1
12=18-3A1+2A1
-6=-A1
A1=6
A0=0
"""
def fr(n):
    l=[6,12]
    for i in range(2,n+1):
        l.append(5*l[i-1]-6*l[i-2])
    return l[-1]
def fi(n):
    return 6*(2**n)
flag=True
for i in range(2,1000):
    flag = flag and fr(i)==fi(i)
print(flag)
    
