from HW2Q3 import ceaser_cypher

def ceaser_decrypt(ciphertext, first='a', last='z'):
	return [ceaser_cypher(ciphertext, key, first, last) for key in range(1, ord(last) - ord(first))]


if __name__ == "__main__":
	ciphertext = input("Enter the ciphertext:\n")
	for message in ceaser_decrypt(ciphertext):
		print(message, '\n')


# This program can be made more efficient by using a dictionary to detect if the first few decrypted words are real words. If they aren't, then there is no need to decrypt the entire message and the program can move on to the next possible key.