from cs50 import get_string
import string


def main():
    text = get_string("Text: ")
    text = text.split()
    word_number = len(text)
    letter_count = 0
    sentence_count = 0
    for i in range(word_number):
        if "." in text[i] or "!" in text[i] or "?" in text[i]:
            sentence_count += 1
            # print(text[i])
    # print(sentence_count, "/", word_number)
    S = 100 * sentence_count / word_number

    punctuation_list = [*string.punctuation]
    for i in range(word_number):
        for j in range(len(punctuation_list)):
            if punctuation_list[j] in text[i]:
                # print(text[i])
                text[i] = text[i].replace(punctuation_list[j], "")
                # print(text[i])
        letter_count = letter_count + len(text[i])
    # print(letter_count, "/", word_number)
    L = 100 * letter_count / word_number
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Grade", stindex)


# L is the average number of letters per 100 words in the text
# S is the average number of sentences per 100 words in the text.
# S a period, exclamation point, or question mark indicate the end of a sentence

main()
