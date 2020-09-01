from itertools import permutations

# message - an encrypted string that is to be decrypted
# chars - an iterable of characters in order of frequency from most frequent to least frequent
# given - a dictionary of character translations we already know
def decrypt(message, chars, given = {}):
	message = message.lower()
	unknown_chars = list(filter(lambda char: char not in given.keys(), chars))
	# frequencies is a dictionary mapping from each character to its frequency (initialised to 0)
	frequencies = dict()
	for char in unknown_chars:
		frequencies[char] = 0
	for char in message:
		if char in unknown_chars:
			frequencies[char] += 1

	# reverse chars and remove known chars
	chars = list(filter(lambda char: char not in given.values(), chars))[::-1]

	# frequencies_list is an array of the unknown characters in the message sorted by the frequency (lowest first) in which they appear in the message
	frequencies_list = sorted(filter(lambda char: frequencies[char] != 0, frequencies.keys()), key = lambda char: frequencies[char])

	# Try mapping different permutations of the frequencies
	for permutation in permutations(chars):
		# swap each letter in the encrypted message with the corresponding letter according to frequency
		decrypted = ""
		for char in message:
			if char in frequencies_list:
				# get a char from permutation in the corresponding index (from the end) where char is in frequencies_list
				decrypted += permutation[frequencies_list.index(char) - len(frequencies_list)]
			elif char in given.keys():
				decrypted += given[char]
			else:
				decrypted += char

		yield decrypted


message = input("Enter an encrypted message:\n")
chars = "etaoinshrdlcumwfgypbvkjxqz"
assumptions = {}
generator = decrypt(message, chars)
while True:
	possible_decryption = next(generator)
	print()
	print(possible_decryption)
	print()
	command = input("To try another combination press enter.\nOr you may enter some assumptions in the form \"a=b,c=?,d=d\" (use ? to remove an assumption, use a=a to lock a in its place).\nTo exit, enter 0.\n")

	if command == "0":
		break

	if command == "":
		continue

	assumptions = {possible_decryption[message.index(k)]:v for (k,v) in filter(lambda kv: kv[0] in message, assumptions.items())}

	for assumption in command.split(','):
		kv_pair = assumption.split('=')
		if kv_pair[1] == '?':
			assumptions.pop(kv_pair[0], None)
		else:
			key = kv_pair[0].strip()[0].lower()
			value = kv_pair[1].strip()[0].lower()
			if 'a' <= key <= 'z' and 'a' <= value <= 'z':
				# if the assumption's lhs is already used, remove it from the assumptions
				for k, v in assumptions.items():
					if v == value:
						assumptions.pop(k, None)
						break
				assumptions[key] = value

	message = possible_decryption
	generator = decrypt(message, chars, assumptions)