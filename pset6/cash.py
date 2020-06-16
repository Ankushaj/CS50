from cs50 import get_float
while True:
    dollars = get_float("Change owned: ")
    if dollars > 0:
        break

cent = round(dollars*100)
quarter = cent // 25
dime = (cent -(quarter * 25)) // 10
nickel = (cent -(quarter * 25) - (dime * 10)) // 5
penny = cent - (quarter * 25) - (dime * 10) - (nickel * 5)
coins = quarter + dime + nickel + penny
print(coins)