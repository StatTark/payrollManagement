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
    if("UPDATE" or "INSERT" or "DELETE" in okuma):
        mycursor.execute(okuma,)
        mycursor._connection.commit()
        mycursor.close()
    else:

        mycursor.execute(okuma,)
        result = mycursor.fetchall()

        f.truncate(0) #dosya içeriği siler
        with open("C:/Users/StatTark/CLionProjects/payroll/cmake-build-debug/databaseCollaborator.txt","a")as c:
            for i in result:
                for k in i:
                    c.write(str(k)+" ")
                c.write("< ")
                c.write("\n")
        mycursor.close()







'''db = MySQLdb.connect(host="localhost",
                     user="root",
                     passwd="",
                     db="payroll")
cursor = db.cursor()
"""sorgu="SELECT * from users"
cursor.execute(sorgu,)
result = cursor.fetchall()
print(result)"""

with open("cmake-build-debug/filename.txt","r+") as f:
    okuma =  f.read()
    print(okuma +" (Sql sorgusu)")
    cursor.execute(okuma,)
    result = cursor.fetchall()
    f.truncate(0) #dosya içeriği siler
    with open("cmake-build-debug/filename.txt","a")as c:
        for i in result:
            print(i,"\n")
            c.write(str(i))
            c.write("\n")
cursor.close()'''