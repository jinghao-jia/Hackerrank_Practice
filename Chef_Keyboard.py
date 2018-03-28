def numfactor(n, m, c):
	result, i = 0, 0
	while i <= m:
		i += 1
		if c % i:
			continue
		if (c / i) > n:
			continue
		result += 1
		
	return result

def main():
	num = int(input().strip())
	for i in range(0, num):
		n, m, c = map(int, input().strip().split(' '))
		print(numfactor(n, m, c))

if __name__ == "__main__":
    main()
