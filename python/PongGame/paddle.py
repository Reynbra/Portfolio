from turtle import Turtle

COLOR = "white"
MOVE_DISTANCE = 20


class Paddle(Turtle):

    def __init__(self, position):
        super().__init__()
        self.shape("square")
        self.penup()
        self.color(COLOR)
        self.shapesize(stretch_wid=5, stretch_len=1)
        self.goto(position)

    def go_up(self):
        if self.ycor() < 245:
            new_y = self.ycor() + MOVE_DISTANCE
            self.goto(self.xcor(), new_y)

    def go_down(self):
        if self.ycor() > -245:
            new_y = self.ycor() - MOVE_DISTANCE
            self.goto(self.xcor(), new_y)
