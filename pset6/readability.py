from cs50 import get_string
s = get_string("text: \n").strip()

letter = 0
word = 0
sentence = 0

for i in range(len(s)):
    if s[i].isalpha():
        letter += 1
    if (i == 0 and s[i] != ' ') or (i != len(s) - 1 and s[i] == ' ' and s[i+1] != ' '):
        word += 1
    if s[i] == '.' or s[i] == '?' or s[i] == '!':
        sentence += 1

L = 100 * letter / word
S = 100 * sentence / word
I = round(0.0588 * L - 0.296 * S - 15.8)

if I >= 16:
    print("Grade 16+")
if I < 1:
    print("Before Grade 1")
if I >= 1 and I < 16:
    print(f"Grade {I}")