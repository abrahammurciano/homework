from HW2Q1 import char_shift

def ceaser_cypher(message, offset, first='a', last='z'):
	return "".join([char_shift(char, offset, first, last) for char in message.lower()])

if __name__ == "__main__":
	message = input("Enter a message to encrypt:\n")
	offset = int(input("Enter an offset to use in your ceaser cypher:\n"))
	print("Your encrypted message is:")
	print(ceaser_cypher(message, offset))