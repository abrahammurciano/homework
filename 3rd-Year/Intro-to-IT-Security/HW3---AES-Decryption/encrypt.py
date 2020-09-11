from base64 import urlsafe_b64encode
from Crypto.Cipher import AES # needs `pip install pycryptodome`
from Crypto import Random

BS = 16
pad = lambda s: s + (BS - len(s) % BS) * chr(BS - len(s) % BS)

def base64_unpad(s):
	return s.rstrip('=')

def encrypt(key, msg):
	iv = Random.new().read(BS)
	cipher = AES.new(key.encode(), AES.MODE_CFB, iv, segment_size=AES.block_size * 8)
	encrypted_msg = cipher.encrypt(pad(str(msg)).encode())
	return base64_unpad(urlsafe_b64encode(iv + encrypted_msg).decode())

if __name__ == "__main__":
	message = input("Enter a message:\n")
	key = input("Enter a key:\n")
	print(encrypt(key, message))