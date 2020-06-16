from sys import argv, exit
import csv

# python dna.py databases/large.csv sequences/5.txt

def maximun_substring(seq, STR):
    ans = [0] * len(seq)
    for i in range(len(seq) - len(STR), -1, -1):
        if seq[i : i + len(STR)] == STR:
            if i + len(STR) > len(seq) -1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(STR)]
    return max(ans)

def print_match(reader, current):
    for line in reader:
        name = line[0]
        values = [int(val) for val in line[1:]]
        if values == current:
            print(name)
            return
    print ("No match")


def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    with open (argv[1]) as csv_file:
        reader = csv.reader(csv_file)
        all_seq = next(reader)[1:]

        with open (argv[2]) as txt_file:
            seq = txt_file.read()
            current = [maximun_substring(seq, STR) for STR in all_seq]    #append

        print_match(reader, current)

if __name__ == '__main__':
    main()


