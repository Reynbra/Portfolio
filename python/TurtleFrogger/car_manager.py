from turtle import Turtle
import random

COLORS = ["red", "orange", "yellow", "green", "blue", "purple"]
STARTING_MOVE_DISTANCE = 5
MOVE_INCREMENT = 10
LEVEL_UP_SPEED = 1
CAR_SPAWN_RATE_CHANCE = 10
CAR_START_POSITIONS = [-210, -200, -160, -120, -80, -40, 0, 40, 80, 120, 160, 200, 210]


class CarManager(Turtle):
    def __init__(self):
        super().__init__()
        self.hideturtle()
        self.all_cars = []
        self.car_speed = STARTING_MOVE_DISTANCE
        self.car_spawn_rate = CAR_SPAWN_RATE_CHANCE

    def create_car(self):
        random_chance = random.randint(1, self.car_spawn_rate)
        if random_chance == 1:
            new_car = Turtle("square")
            new_car.penup()
            random_y_pos = random.choice(CAR_START_POSITIONS)
            new_car.color(random.choice(COLORS))
            new_car.shapesize(stretch_wid=1.25, stretch_len=3)
            new_car.goto(300, random_y_pos)
            self.all_cars.append(new_car)

    def car_movement(self):
        for car in self.all_cars:
            car.backward(self.car_speed)

    def level_up(self):
        self.car_speed += LEVEL_UP_SPEED
        if CAR_SPAWN_RATE_CHANCE > 3:
            self.car_spawn_rate -= 1
