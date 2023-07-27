import turtle
import pandas
import time

STATE_FONT = ('Arial', 8, 'normal')
INCORRECT_FONT = ('Arial', 15, 'normal')

df = pandas.read_csv("50_states.csv")

screen = turtle.Screen()
screen.title("U.S. States Game")
image = "blank_states_img.gif"
screen.addshape(image)
turtle.shape(image)
words = turtle.Turtle()
words.hideturtle()
state_name_writer = turtle.Turtle()
state_name_writer.hideturtle()
guessed_states = []
game_is_on = True


while game_is_on and len(guessed_states) < 50:
    answer_state = screen.textinput(title=f"{len(guessed_states)}/50 States Correct:"
                                          f" Guess the State", prompt="What's another state name?")
    ans_state_cap = answer_state.title()
    all_states = df.state.to_list()

    if ans_state_cap == 'Quit' or ans_state_cap == 'Exit':
        missing_states = []
        for state in all_states:
            if state not in guessed_states:
                missing_states.append(state)
        new_data = pandas.DataFrame(missing_states)
        new_data.to_csv("states_to_learn.csv")
        break
    elif ans_state_cap in guessed_states:
        words.penup()
        words.goto(0, 0)
        words.write(f"You've already guessed {ans_state_cap}. Try another state.", align='center',
                    font=INCORRECT_FONT)
        time.sleep(1)
        words.clear()
    elif ans_state_cap in all_states:
        guessed_states.append(ans_state_cap)
        state_name_writer.penup()
        state_data = df[df.state == ans_state_cap]
        state_name_writer.goto(int(state_data.x), int(state_data.y))
        state_name_writer.write(ans_state_cap, align='center', font=STATE_FONT)
        if len(guessed_states) == 50:
            words.penup()
            words.goto(0, 0)
            words.write("Congrats! You're a state name master!", align='center', font=INCORRECT_FONT)
            time.sleep(5)
            game_is_on = False
            turtle.bye()
    else:
        words.penup()
        words.goto(0, 0)
        words.write("Sorry, that's incorrect. Please try again.", align='center', font=INCORRECT_FONT)
        time.sleep(0.5)
        words.clear()
