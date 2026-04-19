class IImage:
    def __init__(self):
        pass

    def display(self):
        pass
class  RealImage(IImage):
    def __init__(self, filename):
        super().__init__()
        self.filename = filename

    def display(self):
        print(f"[Real Image ] Loading Image from Disk: {self.filename}")
class ImageProxy(IImage):
    def __init__(self, filename):
        super().__init__()
        self.filename = filename
        self.real_image = None

    def display(self):
        if self.real_image is None:
            self.real_image = RealImage(self.filename)
        self.real_image.display()
def main():
    image1 = ImageProxy("image1.jpg")
    image1.display()

if __name__ == "__main__":
    main()