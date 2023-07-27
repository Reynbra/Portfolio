from turtle import Screen
from paddle import Paddle
from ball import Ball
from scoreboard import Scoreboard
import time

screen = Screen()
screen.bgcolor("black")
screen.setup(width=800, height=600)
screen.title("Pong")
screen.tracer(0)

scoreboard = Scoreboard()
p1_paddle = Paddle((-350, 0))
p2_paddle = Paddle((350, 0))
ball = Ball((0, 0))

screen.listen()
screen.onkeypress(p1_paddle.go_up, "w")
screen.onkeypress(p1_paddle.go_down, "s")
screen.onkeypress(p2_paddle.go_up, "Up")
screen.onkeypress(p2_paddle.go_down, "Down")

game_is_on = True
while game_is_on:
    game_is_on = scoreboard.game_over()
    time.sleep(ball.move_speed)
    screen.update()
    ball.move()

    if ball.ycor() > 280 or ball.ycor() < -280:
        ball.bounce_y()

    if ball.distance(p1_paddle) < 50 and ball.xcor() < -320:
        ball.bounce_x_p1_paddle()
    if ball.distance(p2_paddle) < 50 and ball.xcor() > 320:
        ball.bounce_x_p2_paddle()

    if ball.xcor() > 380:
        scoreboard.increase_p1_score()
        ball.reset_position()
    if ball.xcor() < -380:
        scoreboard.increase_p2_score()
        ball.reset_position()

screen.exitonclick()
