import sha256_hash
import sqlite3
import random
import string

def add_user(username: str, password: str, db_conn):
	salt = rand_string(255)
	hashed_password = sha256_hash.sha256_hash(password + salt)
	db_conn.cursor().execute("""
		insert into users
			(username, hash, salt)
		values
			(?, ?, ?);
	""", (username, hashed_password, salt)).close()
	db_conn.commit()


def rand_string(length: int, chars: str = string.ascii_letters + string.digits):
	return "".join(random.choice(chars) for i in range(length))


if __name__ == "__main__":
	conn = sqlite3.connect("users.db")
	conn.cursor().execute("""
		create table if not exists users (
			username varchar(255) primary key,
			hash char(64),
			salt char(255)
		);
	""").close()
	conn.commit()
	username = input("Username: ")
	password = input("Password: ")
	add_user(username, password, conn)
	conn.close()