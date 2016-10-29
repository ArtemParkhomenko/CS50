money = -1
while money < 0:
    print("O hai! How much change is owed?")
    money = float(input())
leftover = round(money * 100)

# Quarters
count = (leftover // 25)
leftover %= 25

# Dimes
count += leftover // 10
leftover %= 10

# Nickels
count += leftover // 5
leftover %= 5

# Pennies
count += leftover
print(count)
