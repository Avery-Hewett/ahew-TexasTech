##Avery Hewett
##CS 1411
##11/13/2019

def main():
    ##file name input
    fileName = input("What is the name of the file to import: ")
    
    print()
    dictCount = {}
    case = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    
    try:
        file = open(fileName, 'r')

        for line in file:
            words = line.split()
            for i in words:
                j = "".join(c for c in i if c in case)
                if j.isalpha() or j.isnumeric() and j != "":
                    if j.lower() in dictCount:
                        dictCount[j.lower()] += 1
                    else:
                        dictCount[j.lower()] = 1
        #reverse sort, most occurances first
        d_view = [(v,k) for k,v in dictCount.items()]
        d_view.sort(reverse=True)
        for v,k in d_view:
            print ("%d\t%s" % (v, k))
    ##exception for no file        
    except FileNotFoundError as e:
        print (e)


main()
