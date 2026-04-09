class dept:
    def __init__(self, name, id):
        self._deptName = name
        self._deptId = id

    def calling(self):
        print(f"Department {self._deptName} is handling the complaint.")
    @property
    def deptName(self):
            return self._deptName
    @property
    def deptId(self):
        return self._deptId
    