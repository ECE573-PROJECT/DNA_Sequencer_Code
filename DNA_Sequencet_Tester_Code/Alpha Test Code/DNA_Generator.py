'''
The code is based on the a class project at Rutgers University.

Project Title : DNA Sequencer Detector
Class : Data Structures and Algorithms
Course No : ECE573
Professor : Jha
Semester : Spring 2018
Written by Tina Drew
Debugged by Tina Drew
Tested by Tina Drew

Group Participants : Divyaprakash Dhurandhar, Tina Drew, Anirudh Kulkarni, and Juhi Tripathi

This code creates files with randon characters to simulate a randomly generate DNA sequence
'''




from _overlapped import NULL
from numpy.core.multiarray import empty
import random
import os
import csv

class glVar():
    dataSum = []
    dataArr = []
    writeToFile = ''
    directory = ""
    myFile = ''
    dataFile = ''
    NumNodes = 0
    NumEdges = 0

'''The code below opens and dialog box and allows the user to select a directory''' 
def getFilePath():
    import tkinter as tk
    from tkinter import filedialog
    #import os
    import random

    root = tk.Tk()
    root.withdraw()

    #glVar.dataFile = filedialog.askopenfilename(parent=root,title='Select files to be tested')
    #(glVar.directory, fileN) = os.path.split(glVar.dataFile)
    glVar.directory = filedialog.askdirectory()

    file = 'Q5_Results.txt'
    glVar.myFile = open(os.path.join(glVar.directory, file), "a+" )

'''Writes DNA Symbols to file'''
def writeTextToFile(N):
    symbolsDNA = ['a', 'c', 'g', 't']
    for i in range(N):
        a = random.randint(0,3)
        line = symbolsDNA[a]
        glVar.myFile.write(line)
        #print(line)
    
def main():
    getFilePath()
    arrN = [700]
        
    for i in range(0, len(arrN)):
        '''Sets filename'''
        file = 'DNA_String_' + str(arrN[i]) + '.txt'
        glVar.myFile = open(os.path.join(glVar.directory, file), "a+" )
        
        writeTextToFile(arrN[i])
        
main()
input('Press enter to exit')