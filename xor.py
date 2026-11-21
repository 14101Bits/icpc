def count_xor_eq_sum(a):
    n = len(a)
    ans = 0
    r = 0
    xor_sum = 0
    total_sum = 0

    for l in range(n):
        
        while r < n and (xor_sum ^ a[r]) == (total_sum + a[r]):
            xor_sum ^= a[r]
            total_sum += a[r]
            r += 1

      
        ans += r - l

       
        xor_sum ^= a[l]
        total_sum -= a[l]

    return ans



n = int(input())
a = list(map(int, input().split()))


print(count_xor_eq_sum(a))
