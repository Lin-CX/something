
if __name__ == "__main__":
    n = int(input("Input: "))
    # preprocessing
    if n < 0:
        print("Wrong input!")
    if n % 2 == 0:
        n += 1
    # print quadrilateral
    for i in range(n):
        for j in range(abs(n//2 - i)):
            print(" ", end=" ")
        for k in range(2 * (n//2 - abs(n//2 - i)) + 1):
            print("*", end=" ")
        print()