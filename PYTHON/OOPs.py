class Employee:
    language = "py"
    salary = 1200000
    
harry = Employee()
print(harry.language , harry.salary)

harry.name = "Harry Potter" #object attribute
print(harry.name , harry.language , harry.salary) #class attribute


print(harry)