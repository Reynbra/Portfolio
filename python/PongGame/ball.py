from turtle import Turtle


class Ball(Turtle):
    def __init__(self, position):
        super().__init__()
        # self.tracer(1)
        self.penup()
        self.shape("circle")
        self.color("white")
        self.setpos(position)
        self.x_move = 10
        self.y_move = 10
        self.move_speed = 0.1

    def move(self):
        new_x = self.xcor() + self.x_move
        new_y = self.ycor() + self.y_move
        self.goto(new_x, new_y)

    def bounce_y(self):
        self.y_move *= -1

    def bounce_x_p1_paddle(self):
        self.x_move = (abs(self.x_move))
        self.move_speed *= 0.9

    def bounce_x_p2_paddle(self):
        self.x_move = -(abs(self.x_move))
        self.move_speed *= 0.9

    def reset_position(self):
        self.goto(0, 0)
        self.move_speed = 0.1
        self.bounce_x_p2_paddle()
