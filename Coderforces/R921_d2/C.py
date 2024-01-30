def check_subsequences(t, test_cases):
    results = []

    for i in range(t):
        n, k, m = test_cases[i][:3]
        s = test_cases[i][3]

        possible_subsequences = set()
        for j in range(k):
            for l in range(k):
                possible_subsequences.add(chr(ord('a') + j) + chr(ord('a') + l))

        is_subsequence = all(subsequence in s for subsequence in possible_subsequences)

        if is_subsequence:
            results.append("YES")
        else:
            results.append("NO")
            # Find a string of length n that does not occur as a subsequence of s
            missing_subsequence = ""
            for j in range(k):
                for l in range(k):
                    candidate = chr(ord('a') + j) + chr(ord('a') + l)
                    if candidate not in s:
                        missing_subsequence = candidate
                        break
                if missing_subsequence:
                    break
            results.append(missing_subsequence)

    return results


# Input parsing
t = int(input())
test_cases = []

for _ in range(t):
    case = list(map(int, input().split()))
    s = input().strip()
    case.append(s)
    test_cases.append(case)

# Check subsequences and print results
results = check_subsequences(t, test_cases)
for i in range(0, len(results), 2):
    print(results[i])
    if results[i] == "NO":
        print(results[i + 1])
