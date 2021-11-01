def gpa_cal(scores : str,base:int = 10) -> float:
    """Return  float Grade Point Average for anyy base with default as 10
        A- and B+ aree treated as similar, althouh functionality can be modified"""

    gpa_final = 0.0
    scores = scores.upper() # To allow for mistypes in scores entered
    gpa_final += scores.count('+') # increments score by 1 for each plus
    gpa_final -= scores.count('-') # decrements score by 1 for each minus

    # Remove + and minus from string
    scores = "".join(scores.split('+')) # Splits across + and joins scores string again
    scores = "".join(scores.split('-')) # Splits across - and joins scores string again
    if len(scores) == 0:
        raise ValueError("Invalid Grades entered as input")

    grading = {} # dict stores value alloted to each grade
    for value in range(0,base):
        grading[chr(65+value)] = base-value-1

    for grade in scores:
        try:
            gpa_final += grading[grade]
        except KeyError as e:
            raise KeyError("Incorrect Symbol entered {!r}".format(e))

    gpa_final = gpa_final/len(scores)
    return gpa_final

if __name__ == "__main__":
    print(gpa_cal('AAA+BCADE',10)) # Test case in issue
