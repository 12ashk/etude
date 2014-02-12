def main():
    string = raw_input()
    string_2 = ''
    for i in string:
        num = int(hex(ord(i)), 16)
        if num <= int(hex(ord('M')), 16)\
                or int(hex(ord('a')), 16) <= num <= int(hex(ord('m')), 16):
            string_2 += chr(num+13)
        else:
            string_2 += chr(num-13)
    print string_2

if __name__ == '__main__':
    main()
