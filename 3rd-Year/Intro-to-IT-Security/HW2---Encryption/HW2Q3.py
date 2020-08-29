def ceaser_cypher(message, offset):
	message = message.lower()
	encrypted = ""
	for char in message:
		encrypted += ((chr((ord(char) - ord('a') + offset) % 26 + ord('a'))) if 'a' <= char <= 'z' else char)
	return encrypted


message = input("Enter a message to encrypt:\n")
offset = int(input("Enter an offset to use in your ceaser cypher:\n"))
print("Your encrypted message is:")
for char in ceaser_cypher(message, offset):
	print(char, end = '')