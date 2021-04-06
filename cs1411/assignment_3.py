
def similar_items(list1, list2):
    x = []
    for i in range(len(list1)):
        for j in range(len(list2)):
            if list1[i] == list2[j]:
                x.append(list1[i])

    return x

def unique_items(list1, list2):
    x = []
    for i in range(len(list1)):
        for j in range(len(list2)):
            if list1[i] == list2[j]:
                break
            elif j == len(list2)-1:
                x.append(list1[i])

    for k in range(len(list2)):
        for l in range(len(list1)):
            if list2[k] == list1[l]:
                break
            elif l == len(list1)-1:
                x.append(list2[k])

    return x

def sum_items(myList):
    x = 0
    for i in range(len(myList)):
        x += myList[i]

    return x
    
def multiply_items(myList):
    x = 1
    for i in range(len(myList)):
        x *= myList[i]

    return x

def minimum_item(myList):
    x = 99999
    for i in range(len(myList)):
        if myList[i] < x:
            x = myList[i]

    return x

def maximum_item(myList):
    x = -99999
    for i in range(len(myList)):
        if myList[i] > x:
            x = myList[i]

    return x
