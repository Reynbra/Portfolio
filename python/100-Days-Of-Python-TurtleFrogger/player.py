from turtle import Turtle

STARTING_POSITION = (0, -280)
UP = 90
DOWN = 270
LEFT = 180
RIGHT = 0
MOVE_DISTANCE = 20
FINISH_LINE_Y = 280


class Player(Turtle):
    def __init__(self):
        super().__init__()
        self.shape("turtle")
        self.color("green")
        self.penup()
        self.shapesize(stretch_wid=1.25, stretch_len=1.25)
        self.go_to_start()

    def move_up(self):
        self.setheading(UP)
        # self.forward(MOVE_DISTANCE)
        new_y = self.ycor() + MOVE_DISTANCE
        self.goto(self.xcor(), new_y)

    def move_down(self):
        self.setheading(DOWN)
        new_y = self.ycor() - MOVE_DISTANCE
        self.goto(self.xcor(), new_y)

    def move_left(self):
        self.setheading(LEFT)
        new_x = self.xcor() - MOVE_DISTANCE
        self.goto(new_x, self.ycor())

    def move_right(self):
        self.setheading(RIGHT)
        new_x = self.xcor() + MOVE_DISTANCE
        self.goto(new_x, self.ycor())

    def go_to_start(self):
        self.setheading(UP)
        self.goto(STARTING_POSITION)
