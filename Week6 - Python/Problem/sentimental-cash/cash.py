def get_float(prompt):
    while True:
        try:
            return float(input(prompt))
        except ValueError:
            pass


def main():
    quarters = 0.25
    dimes = 0.10
    nickels = 0.05
    pennies = 0.01
    coins = 0
    while True:
        change = get_float("Change: ")
        if change < 0:
            continue
        else:
            while (change // quarters) != 0:
                change = round(change - quarters, ndigits=2)
                coins += 1
                # print(quarters, ":",change)
            while (change // dimes) != 0:
                change = round(change - dimes, ndigits=2)
                coins += 1
                # print(dimes, ":",change)
            while (change // nickels) != 0:
                change = round(change - nickels, ndigits=2)
                coins += 1
                # print(nickels, ":",change)
            while (change // pennies) != 0:
                change = round(change - pennies, ndigits=2)
                coins += 1
            # print(pennies, ":",change)
            print(coins)
            break


main()
