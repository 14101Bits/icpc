
def count_increasing_subarrays(a):
    n = len(a)
    ans = 0
    length = 1 

    for i in range(1, n):
        if a[i] > a[i - 1]:
            length += 1
        else:
            ans += length * (length + 1) // 2
            length = 1

    ans += length * (length + 1) // 2
    return ans


n = int(input())
a = list(map(int, input().split()))
print(count_increasing_subarrays(a))
