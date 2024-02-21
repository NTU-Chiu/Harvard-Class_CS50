import csv
import sys


def main():
    # TODO: Check for command-line usage
    # python dna.py databases/small.csv sequences/1.txt
    if len(sys.argv) != 3:
        print("Wrong command-line usage")
        sys.exit(1)
    # TODO: Read database file into a variable
    # key: ['name', 'AGATC', 'AATG', 'TATC']
    database_list = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        dna_num = len(reader.fieldnames) - 1
        for row in reader:
            database_list.append(row)
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        sequence = list(file.read())  # string
        # print(sequence)
    # TODO: Find longest match of each STR in DNA sequence
    # 'AGATC'
    str_dna = {}
    for i in range(1, dna_num + 1):
        str_dna[reader.fieldnames[i]] = 0
    # print(str_dna)
    for i in range(dna_num):
        count_list = [0] * len(sequence)
        now_str = []
        for c in list(str_dna.keys())[i]:
            now_str.append(c)
        now_strlen = len(now_str)
        # print(now_str, now_strlen)
        for j in range(len(sequence) - now_strlen):
            if sequence[j : j + now_strlen] == now_str:
                count_list[j] = 1
            # print(sequence[j:j + now_strlen])
        # print("before\n", count_list)
        for j in range(len(sequence) - now_strlen):
            n = 1
            while count_list[j + now_strlen * n] == 1:
                count_list[j] += 1
                n += 1
                # print(count_list[j])
            # print("000")

        # print("after\n", count_list)
        str_dna[list(str_dna.keys())[i]] = max(count_list)
        # print(str[list(str.keys())[i]])
        # print(str_dna)

    # TODO: Check database for matching profiles
    for data in database_list:
        bool_list = []
        for i in range(1, dna_num + 1):
            key = reader.fieldnames[i]
            if data[key] == str(str_dna[key]):
                bool_list.append(0)
            else:
                bool_list.append(1)
        if sum(bool_list) == 0:
            print(data["name"])
            break
    else:
        print("No match")

    return


# def longest_match(sequence, subsequence):
#     """Returns length of longest run of subsequence in sequence."""

#     # Initialize variables
#     longest_run = 0
#     subsequence_length = len(subsequence)
#     sequence_length = len(sequence)

#     # Check each character in sequence for most consecutive runs of subsequence
#     for i in range(sequence_length):

#         # Initialize count of consecutive runs
#         count = 0

#         # Check for a subsequence match in a "substring" (a subset of characters) within sequence
#         # If a match, move substring to next potential match in sequence
#         # Continue moving substring and checking for matches until out of consecutive matches
#         while True:

#             # Adjust substring start and end
#             start = i + count * subsequence_length
#             end = start + subsequence_length

#             # If there is a match in the substring
#             if sequence[start:end] == subsequence:
#                 count += 1

#             # If there is no match in the substring
#             else:
#                 break

#         # Update most consecutive matches found
#         longest_run = max(longest_run, count)

#     # After checking for runs at each character in seqeuence, return longest run found
#     return longest_run


main()
