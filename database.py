import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="",
    database="payroll"
)

mycursor = mydb.cursor()

with open("C:/Users/StatTark/CLionProjects/payroll/cmake-build-debug/databaseCollaborator.txt","r+") as f:
    okuma =  f.read()
    #print(okuma +" (Sql sorgusu)")
    mycursor.execute(okuma,)
    result = mycursor.fetchall()

    f.truncate(0) #dosya içeriği siler
    with open("C:/Users/StatTark/CLionProjects/payroll/cmake-build-debug/databaseCollaborator.txt","a")as c:
        for i in result:
            for k in i:
                c.write(str(k)+" ")
            c.write("< ")
            c.write("\n")
