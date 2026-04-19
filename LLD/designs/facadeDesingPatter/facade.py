class PowerSupply:
    def __init__(self):
        pass

    def providePower(self):
        print("Power supplied!")


class CoolingSystem:
    def __init__(self):
        pass

    def startFans(self):
        print("Fans started!")


class CPU:
    def __init__(self):
        pass

    def initialize(self):
        print("CPU initialized!")


class Memory:
    def __init__(self):
        pass

    def selfTest(self):
        print("Memory self-test completed!")


class HardDrive:
    def __init__(self):
        pass

    def spinUp(self):
        print("Hard drive spinning up!")


class BIOS:
    def __init_subclass__(cls):
        pass

    def boot(self, Cpu, memory, hardDrive):
        print("Booting system...")
        Cpu.initialize()
        memory.selfTest()
        hardDrive.spinUp()


class OperatingSystem:
    def __init_subclass__(cls):
        pass

    def Load(self):
        print("Operating System :Loading into Memory")


class ComputerFacade:
    st = CoolingSystem()
    mem = Memory()
    fan = CoolingSystem()
    op = OperatingSystem()
    Hd = HardDrive()
    cpu = CPU()
    bios = BIOS()
    power = PowerSupply()

    def __init_subclass__(cls):
        pass

    def StartComputer(self):
        print("Starting computer...")
        self.power.providePower()
        self.st.startFans()
        self.mem.selfTest()
        self.cpu.initialize()
        self.bios.boot(self.cpu, self.mem, self.Hd)
        self.op.Load()


def main():
    computer = ComputerFacade()
    computer.StartComputer()


main()
