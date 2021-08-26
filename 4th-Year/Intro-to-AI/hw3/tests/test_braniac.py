from player import Player
from typing import Iterable, Tuple
from connect_four_board import ConnectFourBoard
from players.human import Human
from players.braniac import Braniac
from cell import Cell
import pytest


class TestBraniac:
	@pytest.fixture
	def human(self) -> Human:
		return Human()

	@pytest.fixture
	def braniac(self) -> Braniac:
		return Braniac()

	def make_board(
		self,
		player1: Player,
		player2: Player,
		p1_cells: Iterable[Tuple[int, int]],
		p2_cells: Iterable[Tuple[int, int]],
		active_player: int,
		last_play: int,
	) -> ConnectFourBoard:
		grid = [[Cell(row, col) for col in range(7)] for row in range(6)]
		for row, col in p1_cells:
			grid[row][col] = Cell(row, col, player1)
		for row, col in p2_cells:
			grid[row][col] = Cell(row, col, player2)
		return ConnectFourBoard(
			(player1, player2),
			active_player=active_player,
			last_play=last_play,
			grid=grid,
		)

	@pytest.fixture
	def board1(self, human: Human, braniac: Braniac) -> ConnectFourBoard:
		return self.make_board(
			human,
			braniac,
			[(5, 1), (5, 2), (5, 3)],
			[(5, 4), (4, 3)],
			active_player=1,
			last_play=1,
		)

	@pytest.fixture
	def board2(self, human: Human, braniac: Braniac) -> ConnectFourBoard:
		return self.make_board(
			braniac,
			human,
			[(1, 3), (2, 1), (2, 2), (2, 3), (4, 1), (4, 3), (5, 1), (5, 3)],
			[(3, 1), (3, 2), (3, 3), (4, 2), (4, 6), (5, 2), (5, 4), (5, 6)],
			active_player=0,
			last_play=4,
		)

	@pytest.fixture
	def board3(self, human: Human, braniac: Braniac) -> ConnectFourBoard:
		return self.make_board(
			human,
			braniac,
			[
				(0, 3),
				(1, 3),
				(2, 4),
				(3, 2),
				(3, 3),
				(4, 3),
				(4, 4),
				(4, 6),
				(5, 0),
				(5, 2),
				(5, 6),
			],
			[
				(0, 2),
				(1, 2),
				(2, 2),
				(2, 3),
				(3, 4),
				(3, 6),
				(4, 2),
				(5, 1),
				(5, 3),
				(5, 4),
			],
			active_player=1,
			last_play=0,
		)

	def test_board1(self, board1: ConnectFourBoard, braniac: Braniac):
		assert braniac.play(board1).cell(5, 0).player == braniac

	def test_board2(self, board2: ConnectFourBoard, braniac: Braniac):
		assert braniac.play(board2).cell(4, 4).is_empty

	def test_board3(self, board3: ConnectFourBoard, braniac: Braniac):
		assert braniac.play(board3).cell(5, 5).is_empty