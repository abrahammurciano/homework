def char_shift(char, offset, first='a', last='z'):
	return chr((ord(char) - ord('a') + offset) % (ord(last) - ord(first) + 1) + ord(first)) if first <= char <= last else char

if __name__ == "__main__":
	char = input("enter a character: ")[0]
	offset = int(input("enter the offset: "))
	print(char_shift(char, offset))