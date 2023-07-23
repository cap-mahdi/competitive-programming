def main():
    a=654654654654654654
    b=987987987987
    print(a*b)
    print(a**b)
def factorial(n):
    result = 1
    for i in range(1,n+1):
        result = result *i
    return result

if(__name__=="__main__"):
    main()
    print(factorial(100))