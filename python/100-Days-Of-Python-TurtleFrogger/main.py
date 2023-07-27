import time
from turtle import Screen
from player import Player
from car_manager import CarManager
from scoreboard import Scoreboard

screen = Screen()
screen.bgcolor("black")
screen.setup(width=600, height=600)
screen.title("Turtler")
screen.tracer(0)

scoreboard = Scoreboard()
player = Player()
car_manager = CarManager()

screen.listen()
screen.onkey(player.move_up, "Up")
screen.onkey(player.move_down, "Down")
screen.onkey(player.move_left, "Left")
screen.onkey(player.move_right, "Right")

game_is_on = True
while game_is_on:
    car_manager.car_movement()
    time.sleep(0.1)
    car_manager.create_car()
    car_manager.car_movement()

    if player.ycor() <= -300:
        player.go_to_start()
    if player.xcor() >= 290:
        player.goto(280, player.ycor())
    if player.xcor() <= -290:
        player.goto(-280, player.ycor())

    if player.ycor() >= 270:
        car_manager.level_up()
        player.go_to_start()
        scoreboard.increase_level()
    for car in car_manager.all_cars:
        if car.distance(player) < 30:
            player.go_to_start()
            scoreboard.decrease_lives()
            game_is_on = scoreboard.game_over()
    screen.update()
screen.exitonclick()
