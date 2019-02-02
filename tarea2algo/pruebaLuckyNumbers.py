from sys import stdin

def main():
    bins = []
    for i in range(2,131072):
        num = str(bin(i)[3::])
        num = num.replace("0","4")
        num = num.replace("1","7")
        bins.append(num)
    
    print(len(bins))
    
main()
