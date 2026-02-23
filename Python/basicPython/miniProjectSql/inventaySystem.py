import pyodbc

conn = pyodbc.connect(
    "DRIVER={ODBC Driver 17 for SQL Server};"
    "SERVER=localhost;"
    "DATABASE=InvenetorySystem;"
    "Trusted_Connection=yes;"
)
cursor = conn.cursor()
def displayInventory(item_id):
    cursor.execute(
        "SELECT * FROM InvertaryList WHERE itemId = ?",
        (item_id,)
    )
    rows = cursor.fetchall()
    if rows:
        for row in rows:
            print(f"ID: {row.itemId}, Name: {row.itemName}, Units: {row.noOfUnit}")
    else:
        print("Item not found")
def addItem(itemName, noOfUnit):
    cursor.execute(
        """
        INSERT INTO InvertaryList (itemName, noOfUnit)
        OUTPUT INSERTED.itemId
        VALUES (?, ?)
        """,
        (itemName, noOfUnit)
    )
    last_id = cursor.fetchone()[0]
    conn.commit()
    return last_id
new_id = addItem("Mouse", 200)
displayInventory(new_id)
cursor.close()
conn.close()
