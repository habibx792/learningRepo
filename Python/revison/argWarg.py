def student_info(*args, **kwargs):
    print("Subjects:", args)  # Positional arguments
    print("Details:", kwargs)  # Keyword arguments


# Passing subjects as *args and details as **kwargs
student_info("Math", "Science", "English", Name="Alice", Age=20, City="New York")
