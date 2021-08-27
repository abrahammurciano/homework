from players.braniac import Braniac
from cell import Cell
from typing import Sequence
from statistics import mean


class Jarvis(Braniac):
	def __init__(self, depth: int = None):
		super().__init__(depth=depth)

	def sequence_value(self, cells: Sequence[Cell]):
		result = super().sequence_value(cells)
		if cell_rows := [cell.row for cell in cells]:
			result *= mean(cell_rows) ** 2
		return result

	def __str__(self) -> str:
		return "Jarvis"