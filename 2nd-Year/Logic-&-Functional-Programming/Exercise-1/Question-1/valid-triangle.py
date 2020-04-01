def valid_triangle(a, b, c):
	if a + b > c and a + c > b and b + c > a:
		return True


def main():
	sides = []
	for ith in ['first', 'second', 'third']:
		print('Enter the', ith, 'side of the triangle: ', end='')
		sides.append(int(input()))

	if (valid_triangle(*sides)):
		print('This triangle has valid side lengths')
	else:
		print('This triangle has invalid side lengths.')


if __name__ == "__main__":
	main()
