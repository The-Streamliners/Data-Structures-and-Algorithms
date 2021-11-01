"""
Counts every Line, Whitespaces, Characters and Words written in a text within a file.
This solution relies on the use of Regular Expressions.
"""

from re import findall, split
from os import path

homePath = path.expanduser("~")
filePath = raw_input("Insert the path of your file to count. Example: /documents/sample.txt\nThis is your current home path below, please start from there:\n> %s/" % homePath)
file = open(path.join(homePath, filePath), "r")
fileContent = file.read()

class StringCounter:
    def countLines(self, string):
        result = findall("\n", string)
        print "Lines:", len(result) + 1
    
    def countWhitespaces(self, string):
        result = findall(" ", string)
        print "Whitespaces:", len(result)
    
    def countCharacters(self, string):
        result = findall("(\S|\N)", string)
        print "Characters:", len(result)
    
    def countWords(self, string):
        def filterCondition(elem):
            return elem != ''
        result = filter(filterCondition, split("\n|\s", string))
        print "Words:", len(result)
    
    def countAll(self, string):
        self.countLines(string)
        self.countWhitespaces(string)
        self.countCharacters(string)
        self.countWords(string)

counter = StringCounter()
counter.countAll(fileContent)

file.close()
