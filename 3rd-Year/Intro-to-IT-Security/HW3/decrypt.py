import base64
from Crypto.Cipher import AES

def crack(ciphertext, cars):
	for car in cars:
		car = car.lower()
		key = car.capitalize() + car[::-1].capitalize() + "JCTjct"
		yield decrypt(ciphertext, key)


def decrypt(ciphertext, key):
	ciphertext = base64.b64decode(pad(ciphertext))
	iv = ciphertext[:AES.block_size]
	cipher = AES.new(key, AES.MODE_CBC, iv, segment_size=AES.block_size * 8)
	return unpad(cipher.decrypt(ciphertext[AES.block_size:])).decode('utf-8')


def pad(s):
	return s + '=' * (4 - len(s) % 4)


def unpad(s):
	return s.rstrip('=')


if __name__ == "__main__":
	ciphertext = "YZmWUTcEvGi_5pa-GJBT97nXBQumS8Vd617_xK_LNzSmTudgmWN41Hd_QS_tRv8d"
	cars = ["Abarth", "Alfa Romeo", "Aston Martin", "Audi", "Bentley", "BMW", "Bugatti", "Cadillac", "Chevrolet", "Chrysler", "Citroën", "Dacia", "Daewoo", "Daihatsu", "Dodge", "Donkervoort", "DS", "Ferrari", "Fiat", "Fisker", "Ford", "Honda", "Hummer", "Hyundai", "Infiniti", "Iveco", "Jaguar", "Jeep", "Kia", "KTM", "Lada", "Lamborghini", "Lancia", "Land Rover", "Landwind", "Lexus", "Lotus", "Maserati", "Maybach", "Mazda", "McLaren", "Mercedes-Benz", "MG", "Mini", "Mitsubishi", "Morgan", "Nissan", "Opel", "Peugeot", "Porsche", "Renault", "Rolls-Royce", "Rover", "Saab", "Seat", "Skoda", "Smart", "SsangYong", "Subaru", "Suzuki", "Tesla", "Toyota", "Volkswagen", "Volvo"]
	for message in crack(ciphertext, cars):
		print(message)