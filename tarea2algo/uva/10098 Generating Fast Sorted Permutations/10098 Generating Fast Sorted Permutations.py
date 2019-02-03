from sys import stdin

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
        m.sort()
        #print(m,len(m))
        permutate(m,0,len(m))
        perms = list(perms)
        perms.sort()
        for k in perms:
            print(k)
        print()
main()

