from network_player import Address, NetworkPlayer
from typing import Optional
import socket


class NetworkPlayerClient(NetworkPlayer):
	def __init__(self, symbol: str):
		super().__init__(symbol)
		self.__server: Optional[Address] = None

	@property
	def other_side(self) -> Optional[Address]:
		return self.__server

	def connect(self, server: Optional[Address]) -> None:
		"""Establish a connection with the given server by sending it a message "@host_name".

		Args:
			server (Address): The address of the server to connect to.

		Raises:
			ValueError: If server is not provided.
		"""
		if server is None:
			raise ValueError("Error: Client needs the server's address.")
		self.__server = server
		name = "@" + socket.gethostname()
		self.socket.sendto(name.encode("utf-8"), self.__server)