N, M, L = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

cannot = set()

for _ in range(L):
    C, D = map(int, input().split())
    cannot.add((C - 1, D - 1))

sorted_A = sorted(
    [(value, index) for index, value in enumerate(A)],
    reverse=True
)

sorted_B = sorted(
    [(value, index) for index, value in enumerate(B)],
    reverse=True
)

ans = 0

for a_value, a_index in sorted_A:
    for b_value, b_index in sorted_B:
        if (a_index, b_index) not in cannot:
            ans = max(ans, a_value + b_value)
            break

print(ans)