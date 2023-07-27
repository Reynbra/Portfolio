from turtle import Turtle

SCORE_ALIGNMENT = "center"
SCORE_FONT = ("Courier", 50, "normal")
SCORE_COLOR = "white"
GAME_OVER = "GAME OVER"
GAME_OVER_FONT = ("Courier", 30, "normal")


class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        # self.draw_center_line()
        self.penup()
        self.color(SCORE_COLOR)
        self.p1_score = 0
        self.p2_score = 0
        self.update_scoreboard()

    def draw_center_line(self):
        self.hideturtle()
        self.penup()
        self.pencolor(SCORE_COLOR)
        self.goto(0, -300)
        self.setheading(90)
        for _ in range(600):
            self.pendown()
            self.forward(10)
            self.penup()
            self.forward(10)

    def update_scoreboard(self):
        self.draw_center_line()
        self.goto(-100, 200)
        self.write(self.p1_score, align=SCORE_ALIGNMENT, font=SCORE_FONT)
        self.goto(100, 200)
        self.write(self.p2_score, align=SCORE_ALIGNMENT, font=SCORE_FONT)

    def increase_p1_score(self):
        self.p1_score += 1
        self.clear()
        self.goto(-100, 180)
        self.update_scoreboard()

    def increase_p2_score(self):
        self.p2_score += 1
        self.clear()
        self.goto(100, 180)
        self.update_scoreboard()

    def game_over(self):
        if self.p1_score == 15:
            self.goto(0, 0)
            self.write(arg=f"GAME OVER   P1 WINS!", align=SCORE_ALIGNMENT, font=GAME_OVER_FONT)
            return False
        elif self.p2_score == 15:
            self.goto(0, 0)
            self.write(arg=f"GAME OVER   P2 WINS!", align=SCORE_ALIGNMENT, font=GAME_OVER_FONT)
            return False
        else:
            return True
