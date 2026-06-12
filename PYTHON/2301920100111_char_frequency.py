def char_frequency(string):
    freq = {}
    for i in string:
        freq[i] = freq.get(i,0) + 1 
    return freq

s = input("Enter a string: ")
res = char_frequency(s)
print(res)
