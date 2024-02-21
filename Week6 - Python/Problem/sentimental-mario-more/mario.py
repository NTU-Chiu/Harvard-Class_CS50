from cs50 import get_int


def main():
    while True:
        h = get_int("Height: ")
        if h > 0 and h < 9:
            for i in range(1, h + 1):
                print(" " * (h - i) + "#" * i, end="")
                print("  ", end="")
                print("#" * i, end="")
                print()
            break
        else:
            pass


main()
