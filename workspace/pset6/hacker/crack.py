import sys
import crypt
import string

def nextPassword(pass):
    if pass == '':
        return string.ascii_letters[0]

    if pass[-1] == string.ascii_letters[-1]:
        return nextPassword(pass[:-1]) + string.ascii_letters[0]
    else:
        position = string.ascii_letters.find(pass[-1])
        return pass[:-1] + string.ascii_letters[position+1]


def crack(hash):
    salt = hash[:2]
    password = ''

    while True:
        password = nextPassword(password)
        res = crypt.crypt(password, salt)
        if res == hash:
            break
        if len(password) > 4:
            print("Incorrect input")
            sys.exit(1)

    return password


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage python crack.py hash")
        sys.exit(1)

    print(crack(sys.argv[1]))