#You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.
t = int(input().strip())

for _ in range(t):
    n = int(input().strip())
    arr = list(map(int, input().split()))

    xor_all = 0
    for i in range(1, n + 1):
        xor_all ^= i

    for num in arr:
        xor_all ^= num

    print(xor_all)
