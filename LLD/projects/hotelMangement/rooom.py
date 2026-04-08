from generalInterFace import GeneralMethod
from projects.hotelMangement import generalInterFace
class Room(generalInterFace):
    def __init__(self, room_number, room_type, price):
        self._room_number = room_number
        self._room_type = room_type
        self._price = price
        self._is_available = True
    def checkRoomStatus(self):
        return self._is_available
    def changeRoomStatus(self, is_available):
        if(self._is_available):
           not self._is_available
    def getRoomNumber(self):
        return self._room_number
    def getPrice(self):
        return self._price
    def getRoomType(self):
        return self._room_type
    def setRoomPrice(self, price):
        if(price > 0):
            self._price = price
    def assignGuest(self, guest):
        if(self._is_available):
            self._is_available = False
    def printDetails(self):
        print(f"Room Number: {self._room_number}")
        print(f"Room Type: {self._room_type}")
        print(f"Price: {self._price}")