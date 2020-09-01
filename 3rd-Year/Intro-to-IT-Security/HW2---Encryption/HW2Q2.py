def stat_decrypt(ciphertext, stat_chars_by_freq = "etaoinshrdlcumwfgypbvkjxqz"):
	freq = {char: 0 for char in stat_chars_by_freq}
	ciphertext_lower = ciphertext.lower()
	for char in ciphertext_lower:
		if char in freq.keys():
			freq[char] += 1
	ciphertext_chars_by_freq = sorted(freq.keys(), key=lambda char: freq[char], reverse=True)
	dictionary = dict(zip(ciphertext_chars_by_freq, stat_chars_by_freq))
	return "".join(map(lambda c: dictionary[c] if c in dictionary.keys() else c, ciphertext_lower))


if __name__ == "__main__":
	ciphertext = input("Enter the ciphertext:\n")
	print(stat_decrypt(ciphertext))