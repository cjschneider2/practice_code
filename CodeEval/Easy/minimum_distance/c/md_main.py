import sys
import functools
# NOTE: This solution works... so I'll have to use program a median
#       function in the C version

def median(data):
    data = sorted(data)
    n = len(data)
    if n == 0:
        raise StatisticsError("no median for empty data")
    if n%2 == 1:
        return data[n//2]
    else:
        i = n//2
        return (data[i - 1] + data[i])/2

test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    addr = list(map(int,test.split(" ")))
    num_friends = addr.pop(0) # this removes the first element
                              # from addr giving the list of houses
    med = median(addr)
    sum_addr = list(map(lambda x: abs(x-med),addr))
    a_sum = functools.reduce(lambda x,y: x+y, sum_addr)
    print(int(a_sum))

test_cases.close()
