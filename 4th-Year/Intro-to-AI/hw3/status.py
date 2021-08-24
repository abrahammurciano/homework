from enum import Enum


class Status(str, Enum):
    """Enum representing the status of game"""

    ONGOING = "Game is ongoing"
    PLAYER_1_WINS = "Player 1 wins!"
    PLAYER_2_WINS = "Player 2 wins!"
    TIE = "It's a tie!"
