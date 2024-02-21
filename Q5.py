# calculating value using hash algorithm for each string
def hash_algo(s):
    ans = 0
    for ch in s:
        ans += ord(ch)
        ans *= 17
        ans %= 256
    return ans

if __name__ == "__main__":
    init_seq = "rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7"
    # init_seq = input()
    
    sum = 0
    currs = init_seq.split(',')
    
    for curr in currs:
        sum+=hash_algo(curr)
        
    print("The sum of the results is:", sum)
