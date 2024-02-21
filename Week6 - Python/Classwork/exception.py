def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Please input number.")
            pass

def main():
    x = get_int("x: ")
    y = get_int("y: ")
    z = x / y
    print(f"x / y = {z}")

main()
