alert("Hello, World!");

const patt = document.getElementById("shapeBox");
class Shape {
  draw() {}
}

class Circle extends Shape {
  constructor(radius) {
    super();
    this.radius = radius;
  }

  draw() {
    patt.style.borderRadius = "50%";
    patt.style.width = this.radius * 2 + "px";
    patt.style.height = this.radius * 2 + "px";
  }
}

class Rectangle extends Shape {
  constructor(width, height) {
    super();
    this.width = width;
    this.height = height;
  }

  draw() {
    patt.style.borderRadius = "0";
    patt.style.width = this.width + "px";
    patt.style.height = this.height + "px";
  }
}

class Square extends Shape {
  constructor(side) {
    super();
    this.side = side;
  }

  draw() {
    patt.style.borderRadius = "0";
    patt.style.width = this.side + "px";
    patt.style.height = this.side + "px";
  }
}

class Triangle extends Shape {
  draw() {
    patt.style.width = "0";
    patt.style.height = "0";
    patt.style.borderLeft = "50px solid transparent";
    patt.style.borderRight = "50px solid transparent";
    patt.style.borderBottom = "100px solid red";
  }
}
class ShapeFactory {
  createShape() {}
}

class CircleFactory extends ShapeFactory {
  createShape(radius) {
    return new Circle(radius);
  }
}

class RectangleFactory extends ShapeFactory {
  createShape(width, height) {
    return new Rectangle(width, height);
  }
}

class SquareFactory extends ShapeFactory {
  createShape(side) {
    return new Square(side);
  }
}
class Client {
  constructor(factory) {
    this.factory = factory;
    this.shape = null;
  }

  drawShape(...args) {
    this.shape = this.factory.createShape(...args);
    this.shape.draw();
  }
}

let app = new Client(new CircleFactory());
app.drawShape(50);
side=100;
width=100
length=200
function drawSquare(side) {
  let squareFactory = new SquareFactory();
  let client = new Client(squareFactory);
  client.drawShape(side);
}
function drawRectangle(width, height) {
  let rectangleFactory = new RectangleFactory();
  let client = new Client(rectangleFactory);
  client.drawShape(width, height);
}
function drawCircle(radius) {
    let circleFactory = new CircleFactory();
    let client = new Client(circleFactory);
    client.drawShape(radius);
}
