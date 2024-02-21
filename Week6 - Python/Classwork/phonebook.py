name_list = ["a","b","c"]

input_name = input("your name:")
for name in name_list:
    if name == input_name:
        print("Found")
        break
else: # for loop pairs with else
    print("Not found")
