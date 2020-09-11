import hashlib

def sha256_hash(plaintext: str):
	# convert the plaintext into bytes for the hash function
	bytes_plaintext = plaintext.encode()

	# convert the plaintext bytes into hashed bytes
	hashed_bytes = hashlib.sha256(bytes_plaintext)

	# convert hashed bytes into base 16
	return hashed_bytes.hexdigest()

if __name__ == "__main__":
	print(sha256_hash(input("Enter a string to hash:\n")))