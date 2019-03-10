from sys import stdin


def main():
    num = stdin.readline().strip()
    while num:
        steps = 0
        num = int(num)
        while num :
            #print(num,steps)
            if(num%2==0):
                num /= 2                
            else:
                temp = (num-1)/2
                if( temp % 2 == 0 or temp == 1):
                    num -= 1
                else:
                    num += 1
            steps += 1
        print(steps)
            
        num = stdin.readline().strip()

main()
