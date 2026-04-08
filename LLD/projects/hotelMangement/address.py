class Address:
    def __init__(self, city, country, street, postalCode):
        self._city = city
        self._country = country
        self._street = street
        self._postalCode = postalCode
    @property
    def city(self):
        return self._city
    @city.setter
    def city(self, value):
        self._city = value
    @property
    def country(self):
        return self._country
    @country.setter
    def country(self, value):
        self._country = value
    @property
    def street(self):
        return self._street
    @street.setter
    def street(self, value):
        self._street = value
    @property
    def postalCode(self):
        return self._postalCode
    @postalCode.setter
    def postalCode(self, value):
        self._postalCode = value