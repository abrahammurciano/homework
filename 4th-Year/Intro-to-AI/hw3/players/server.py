from players.abc.network_player import Address, NetworkPlayer
from typing import Optional


class Server(NetworkPlayer):
	def __init__(self, symbol: str):
		super().__init__(symbol)
		self.__client = None

	@property
	def other_side(self) -> Optional[Address]:
		return self.__client

	def connect(self, _=None) -> str:
		"""Wait for a client to connect.

		For a client to connect it should send a message to the socket on `self.address` of the form "@client_name" (without quotes) where "client_name" is the name of the client (62 bytes or less).

		Returns:
			str: The client's name.
		"""
		while True:
			data, self.__client = self.socket.recvfrom(64)
			msg = data.decode("utf-8")
			if msg[0] != "@":
				continue
			return msg[1:]

	def __str__(self) -> str:
		return "Server"