import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="",
    database="payroll_managament"
)

mycursor = mydb.cursor()

with open("./databaseCollaborator.txt", "r+") as f:
    okuma = f.read()
    mycursor.execute(okuma,)
    
    if("UPDATE" in okuma or "INSERT" in okuma or "DELETE" in okuma):
        mycursor._connection.commit()
        mycursor.close()
    else:
        result = mycursor.fetchall()
        f.truncate(0)  # dosya içeriği siler
        with open("./databaseCollaborator.txt", "a")as c:
            for i in result:
                for k in i:
                    c.write(str(k)+" ")
                c.write("\n")
        mycursor.close()
