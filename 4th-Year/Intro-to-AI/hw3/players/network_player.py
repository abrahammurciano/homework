from typing import Optional, Tuple
from player import Player
from connect_four_board import ConnectFourBoard
import socket
import random
from abc import abstractmethod

Address = Tuple[str, int]


class NetworkPlayer(Player[ConnectFourBoard]):
	def __init__(self, symbol: str):
		self.__addr = (
			socket.gethostbyname(socket.gethostname()),
			random.randint(49152, 65535),
		)
		self.__socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		self.__socket.bind(self.__addr)

	@property
	def socket(self) -> socket.socket:
		return self.__socket

	@property
	def address(self) -> str:
		"""The IP and port number this network player is listening on."""
		return f"{self.__addr[0]}:{self.__addr[1]}"

	@property
	@abstractmethod
	def other_side(self) -> Optional[Address]:
		"""The address of the other side of the connection, or None if no connection has been established."""
		pass

	@abstractmethod
	def connect(self, other_side: Optional[Address]) -> Optional[str]:
		"""Connect to the other side of the connection.

		Args:
			other_side (Optional[Address]): If this parameter is given, it will attempt to connect to the given address. Otherwise it will wait for a message on the open socket from the other side.

		Returns:
			Optional[Address]: If no `other_side` was given, it will reuturn the name given by the other side that connected.
		"""
		pass

	def play(self, board: ConnectFourBoard) -> ConnectFourBoard:
		if board.last_play is not None:
			self.__send_move(board.last_play)
		column = self.__receive_move()
		assert column is not None
		return board.place_piece(column)

	def __send_move(self, last_play: Optional[int]):
		if self.other_side is None:
			raise RuntimeError("Error: No connection established.")
		msg = str(last_play) if last_play is not None else "start"
		self.__socket.sendto(msg.encode("utf-8"), self.other_side)

	def __receive_move(self) -> Optional[int]:
		while True:
			data, addr = self.__socket.recvfrom(16)
			if addr != self.other_side:
				continue
			msg = data.decode("utf-8")
			return int(msg) if msg != "start" else None