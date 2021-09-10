from enum import Enum
from typing import Optional


class Gender(Enum):
	MALE = "M"
	FEMALE = "F"

	@classmethod
	def from_string(cls, string: str) -> Optional["Gender"]:
		"""Return a gender from a string, or None if unable to convert.

		Args:
			string (str): The string to convert into a gender.

		Returns:
			Optional[Gender]: The gender the string represents, or None if unable to convert.
		"""
		if not string:
			return None
		if string[0].lower() == "m":
			return cls.MALE
		if string[0].lower() == "f":
			return cls.FEMALE
		return None

	def __str__(self) -> str:
		return self.value