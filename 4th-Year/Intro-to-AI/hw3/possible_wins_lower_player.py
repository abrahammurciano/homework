from possible_wins_player import PossibleWinsPlayer
from cell import Cell
from typing import Sequence
from statistics import mean


class PossibleWinsLowerPlayer(PossibleWinsPlayer):
	def sequence_value(self, cells: Sequence[Cell]):
		result = super().sequence_value(cells)
		if cell_rows := [cell.row for cell in cells]:
			result *= mean(cell_rows) ** 2
		return result

	def __str__(self) -> str:
		return "Jarvis"