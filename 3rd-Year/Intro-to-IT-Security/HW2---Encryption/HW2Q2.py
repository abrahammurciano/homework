from itertools import permutations

# message - an encrypted string that is to be decrypted
# chars - an iterable of characters in order of frequency from most frequent to least frequent
def decrypt(message, chars):
	# frequencies is a dictionary mapping from each character to its frequency (initialised to 0)
	frequencies = dict()
	for char in chars:
		frequencies[char] = 0
	for char in message:
		if 'a' <= char <= 'z':
			frequencies[char] += 1

	# frequencies_list is an array of the alphabet sorted by the frequency in which they appear in the message
	frequencies_list = sorted(filter(lambda char: frequencies[char] != 0, frequencies.keys()), key = lambda char: frequencies[char], reverse = True)

	# Try different permutations of
	for permutation in permutations(frequencies_list):
		# swap each letter in the encrypted message with the corresponding letter according to frequency
		decrypted = ""
		for char in message:
			decrypted += chars[permutation.index(char)] if 'a' <= char <= 'z' else char

		yield decrypted


message = input("Enter an encrypted message:")
chars = "etaoinshrdlcumwfgypbvkjxqz"
for possible_decryption in decrypt(message, chars):
	print(possible_decryption)
	repeat = input("Try again? [Y/n]")
	# Unless input is an N, try again
	if repeat != "" and repeat[0].lower() == 'n':
		break