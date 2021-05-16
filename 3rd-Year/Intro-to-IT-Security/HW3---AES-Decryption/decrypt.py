from base64 import urlsafe_b64encode, urlsafe_b64decode
from Crypto.Cipher import AES  # needs `pip install pycryptodome`


def crack(ciphertext, cars):
	for car in cars:
		car = car.lower().capitalize()
		key = car + car[::-1] + "JCTjct"
		try:
			yield (key, decrypt(ciphertext, key).decode())
		except:
			pass


def decrypt(ciphertext, key):
	encrypted_bytes = urlsafe_b64decode(base64_pad(ciphertext))
	iv = encrypted_bytes[: AES.block_size]
	remaining_bytes = encrypted_bytes[AES.block_size :]
	cipher = AES.new(key.encode(), AES.MODE_CFB, iv, segment_size=AES.block_size * 8)
	return cipher.decrypt(remaining_bytes)


def base64_pad(s):
	return s + "=" * (64 - len(s))


def base64_unpad(s):
	return s.rstrip("=")


if __name__ == "__main__":
	ciphertext = input("Enter the base 64 encoded ciphertext:\n")
	cars = [
		"Abarth",
		"Alfa Romeo",
		"Aston Martin",
		"Audi",
		"Bentley",
		"BMW",
		"Bugatti",
		"Cadillac",
		"Chevrolet",
		"Chrysler",
		"Citroën",
		"Dacia",
		"Daewoo",
		"Daihatsu",
		"Dodge",
		"Donkervoort",
		"DS",
		"Ferrari",
		"Fiat",
		"Fisker",
		"Ford",
		"Honda",
		"Hummer",
		"Hyundai",
		"Infiniti",
		"Iveco",
		"Jaguar",
		"Jeep",
		"Kia",
		"KTM",
		"Lada",
		"Lamborghini",
		"Lancia",
		"Land Rover",
		"Landwind",
		"Lexus",
		"Lotus",
		"Maserati",
		"Maybach",
		"Mazda",
		"McLaren",
		"Mercedes-Benz",
		"MG",
		"Mini",
		"Mitsubishi",
		"Morgan",
		"Nissan",
		"Opel",
		"Peugeot",
		"Porsche",
		"Renault",
		"Rolls-Royce",
		"Rover",
		"Saab",
		"Seat",
		"Skoda",
		"Smart",
		"SsangYong",
		"Subaru",
		"Suzuki",
		"Tesla",
		"Toyota",
		"Volkswagen",
		"Volvo",
	]
	for key, message in crack(ciphertext, cars):
		print("key:\t\t", key, "\nmessage:\t", message)