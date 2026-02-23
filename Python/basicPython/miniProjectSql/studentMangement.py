import pyodbc

conn = pyodbc.connect(
    "DRIVER={ODBC Driver 17 for SQL Server};"
    "SERVER=localhost;"
    "DATABASE=StudentManagementDB;"
    "Trusted_Connection=yes;"
)

cursor = conn.cursor()
def register_student(reg_no, name, father, cls):
    cursor.execute(
        """
        INSERT INTO Students (RegNo, Name, FatherName, Class)
        VALUES (?, ?, ?, ?)
        """,
        (reg_no, name, father, cls)
    )
    conn.commit()
register_student("REG-2026-002", "Sara", "Khan", "9th")
def add_marks(student_id, subject, marks):
    cursor.execute(
        """
        INSERT INTO Marks (StudentID, Subject, Marks)
        VALUES (?, ?, ?)
        """,
        (student_id, subject, marks)
    )
    conn.commit()
def collect_fee(student_id, amount):
    cursor.execute(
        """
        INSERT INTO Fees (StudentID, Amount)
        VALUES (?, ?)
        """,
        (student_id, amount)
    )
    conn.commit()
def student_summary(reg_no):
    cursor.execute(
        """
        SELECT s.Name, s.Class, m.Subject, m.Marks, f.Amount
        FROM Students s
        LEFT JOIN Marks m ON s.StudentID = m.StudentID
        LEFT JOIN Fees f ON s.StudentID = f.StudentID
        WHERE s.RegNo = ?
        """,
        (reg_no,)
    )

    for row in cursor.fetchall():
        print(row)
student_summary("REG-2026-002")