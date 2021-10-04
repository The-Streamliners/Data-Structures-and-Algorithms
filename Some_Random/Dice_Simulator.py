import random //python library for getting random numbers


def diceFace(num):   // main dice function, we call this in a while loop
    if num == 1:     // if we get 1 as our random then this if block gets called
        print("-----")
        print("|" + "   " + "|")
        print("|" + " 0" + " |")
        print("|" + "   " + "|")
        print("-----")
          
        

    if num == 2:     // if we get 2 as our random then this if block gets called	
        print("-----")
        print("|0" + "  " + "|")
        print("|" + "   " + "|")
        print("|" + "  " + "0|")
        print("-----")

    if num == 3:    // if we get 3 as our random then this if block gets called
        print("-----")
        print("|0" + "  " + "|")
        print("|" + " 0 "   + "|")
        print("|" + "  " + "0|")
        print("-----")

    if num == 4:    // if we get 4 as our random then this if block gets called
        print("-----")
        print("|0" + "" + " 0|")
        print("|" + "   " + "|")
        print("|0" + "" + " 0|")
        print("-----")

    if num == 5:    // if we get 5 as our random then this if block gets called
        print("-----")
        print("|0" + "" + " 0|")
        print("|" + " 0 " + "|")
        print("|0" + "" + " 0|")
        print("-----")

    if num == 6:    // if we get 6 as our random then this if block gets called
        print("-----")
        print("|0" + "" + " 0|")
        print("|0" + " " + "0|")
        print("|0" + "" + " 0|")
        print("-----")


str = 'y'
while str == 'y':  
    diceFaceNum = random.randint(1, 6)  //random.randint gives us random integer numbers
    if diceFaceNum == 1:                //calling diceFaceNum function according to random number
        diceFace(1)                     
    elif diceFaceNum == 2:
        diceFace(2)
    elif diceFaceNum == 3:
        diceFace(3)
    elif diceFaceNum == 4:
        diceFace(4)
    elif diceFaceNum == 5:
        diceFace(5)
    elif diceFaceNum == 6:
        diceFace(6)
    print("Would you like to roll once again ?")
    str = input("Enter y for yes and n for a no\n")
