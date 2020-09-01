from base64 import urlsafe_b64encode, urlsafe_b64decode
from Crypto.Cipher import AES
from Crypto import Random

BS = 16
pad = lambda s: s + (BS - len(s) % BS) * chr(BS - len(s) % BS)
unpad = lambda s: s[:-ord(s[len(s) - 1:])]

base64pad = lambda s: s + '=' * (4 - len(s) % 4)
base64unpad = lambda s: s.rstrip('=')

def encrypt(key, msg):
	iv = Random.new().read(BS)
	cipher = AES.new(key, AES.MODE_CFB, iv, segment_size=AES.block_size * 8)
	encrypted_msg = cipher.encrypt(pad(str(msg)))
	return base64unpad(urlsafe_b64encode(iv + encrypted_msg))