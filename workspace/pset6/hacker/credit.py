def getsum(digit):
    return digit // 10 + digit % 10


def checksum(number):
    odd = True
    sum1 = 0
    for i in range(len(number) - 1, -1, -1):
        digit = int(number[i])
        if odd:
            sum1 += digit
        else:
            sum1 += getsum(digit * 2)
        odd = not odd
    if not (sum1 % 10):
        return True
    else:
        return False

cardNum = int(input("Number: "))
cardStr = str(cardNum)

if len(cardStr) < 13 or len(cardStr) > 16 or len(cardStr) == 14:
    print("INVALID")
elif cardStr[0] == '4' and checksum(cardStr):
    print("VISA")
elif cardStr[0] == '3' and (cardStr[1] == '4' or cardStr[1] == '7') and checksum(cardStr):
    print("AMEX")
elif cardStr[0] == '5' and (cardStr[1] >= '1' or cardStr[1] <= '5') and checksum(cardStr):
    print("MASTERCARD")
else:
    print("INVALID")
