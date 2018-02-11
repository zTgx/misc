#-*- coding:utf-8 -*-

#Useage:
#python dereplicated_excel.py xxx.xls 0 1
#列的下标 从0开始

import sys
from sys import argv
sys.path.append("./")
import xlrd   

#cols needs to be process
cols = []
fn = ""
def parse_command():
    filename_ = argv[1];
    
    if len(sys.argv) > 4 :
        print("Error : not supported more than 2 cols!")
        return;

    i=0
    for i in range(2, len(sys.argv)):
        cols.append(int(argv[i]))
    
    print('You Want Process cols = ')
    print(cols)
    print("\n")

def write_to_file(_1, _2, _3):
    try :
        f = open("result.txt", "w")
    except IOError, e:
        print e
    
    f.write("\n ******************** Intersection ********************* \n")
    f.write(str(_1))
    f.write("\n")

    f.write("\n ******************** union **************************** \n")
    f.write(str(_2))
    f.write("\n")

    f.write("\n *********************** difference ********************* \n")
    f.write(str(_3))
    f.write("\n")

    f.close()

def open_excel(fileName=argv[1]):  
    try:  
        fileHandler = xlrd.open_workbook(fileName)  
        return fileHandler  
    except Exception, e:  
        print str(e)      

def scan_excel(sheet_name1=u'Sheet1'):  
    handler = open_excel()  
    page = handler.sheet_by_name(sheet_name1)  
    return page  

def trim_cols(): 
    page = scan_excel()  
    col1 = page.col_values(cols[0])  
    col2 = page.col_values(cols[1])
    
    intersection = list(set(col1).intersection(set(col2)))
    union = list(set(col1).union(set(col2)))
    difference = list(set(col1).difference(set(col2)))

    print("Intersection")
    print(intersection)
    print("\n")

    print("union")
    print(union)
    print("\n")

    print("difference")
    print(difference)
    print("\n")

    write_to_file(intersection, union, difference)

def main(): 
    parse_command()
    trim_cols()  

if __name__ == "__main__":  
    main()  
