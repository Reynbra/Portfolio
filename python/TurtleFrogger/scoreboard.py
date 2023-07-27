from turtle import Turtle

FONT = ("Courier", 20, "normal")
SCORE_COLOR = "white"
ROAD_LINE_COLOR = "white"
SCORE_ALIGNMENT = "left"
LIVES_ALIGNMENT = "right"
GAME_OVER_ALIGNMENT = "center"
LEVEL_TEXT = "Level"
LIVES_TEXT = "Lives"
GAME_OVER = "GAME OVER"


class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.penup()
        self.color(SCORE_COLOR)
        self.level = 0
        self.lives = 3
        self.update_level()
        # self.car_chance = CAR_SPAWN_RATE_CHANCE

    def draw_road_lines(self):
        self.hideturtle()
        self.penup()
        self.pencolor(ROAD_LINE_COLOR)
        self.goto(280, -230)
        self.setheading(180)
        for _ in range(600):
            self.pendown()
            self.forward(20)
            self.penup()
            self.forward(20)
        self.goto(280, 230)
        self.setheading(180)
        for _ in range(600):
            self.pendown()
            self.forward(20)
            self.penup()
            self.forward(20)
        # TODO Make the goto function iterate by a total of 40 pixels
        # TODO Make the loop use the new increased value for position
        # TODO Possibly optimize the drawing function by repeating 10 or so times

    def update_level(self):
        self.draw_road_lines()
        self.goto(-290, 260)
        self.write(f"{LEVEL_TEXT}: {self.level}", align=SCORE_ALIGNMENT, font=FONT)
        self.goto(290, 260)
        self.write(f"{LIVES_TEXT}: {self.lives}", align=LIVES_ALIGNMENT, font=FONT)

    def increase_level(self):
        self.level += 1
        # self.car_chance -= 1
        self.clear()
        self.update_level()

    def decrease_lives(self):
        self.lives -= 1
        self.clear()
        self.update_level()

    def game_over(self):
        if self.lives == 0:
            self.goto(0, 0)
            self.write(arg=f"GAME OVER", align=GAME_OVER_ALIGNMENT, font=FONT)
            return False
        else:
            return True
