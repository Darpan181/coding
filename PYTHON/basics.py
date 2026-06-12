def copyFile(file1 , file2):
    with open(file1 , "r") as f1:
        data = f1.read()
    with open(file2 , "w") as f2:
        f2.write(data)

copyFile("hiscore.txt" , "copy.txt")