import turtle

def square(n):
    for i in range(4):
        turtle.forward(n)
        turtle.right(90)

def sample1(n):
    turtle.right(30)
    for i in range(3):
        square(n)
        turtle.right(120)

def sample2():
    for i in range(36):
        turtle.forward(10)
        turtle.right(10)
        for j in range(3):
            turtle.forward(50)
            turtle.right(120)

def spiral(size, angle):
    if size < 100:
        turtle.forward(size)
        turtle.right(angle)
        spiral(size+2, angle)

if __name__ == '__main__':
    turtle.tracer(0)
    spiral(0, 90)
    turtle.up()
    turtle.goto(140, 20)
    turtle.down()
    spiral(0, 70)
    turtle.mainloop()
