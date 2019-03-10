from sys import stdin

"""
No sirve por el criterio de ordenamiento
"""


def permutate(vec,k,n):
    global perms
    if( k < n):
        for i in range(k,n):
            temp = vec[k]
            vec[k] = vec[i]
            vec[i] = temp
            permutate(vec,k+1,n)
            temp = vec[k]
            vec[k] = vec[i]
            vec[i] = temp
    else:
        perms.add("".join(vec))


def main():
    global perms
    cases = int(stdin.readline().strip())
    for i in range(cases):
        perms = set([])
        m = stdin.readline().strip()
        m = [x for x in m]
        dem = False
        for i in m:
            if i != m[0]:
                dem = True
                break
        if( dem ):
            m.sort()
            #print(m,len(m))
            permutate(m,0,len(m))
            perms = list(perms)
            perms.sort()
            for k in perms:
                print(k)
        else:
            print("".join(m))
        
main()

