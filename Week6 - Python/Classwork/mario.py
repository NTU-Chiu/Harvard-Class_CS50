from cs50 import get_int

def main():
    while True:
        h = get_int("Height:")
        if h > 0:
            w = get_int("Width:")
            if w > 0:
                for i in range(h):
                    print("#"*w)
                break
main()
