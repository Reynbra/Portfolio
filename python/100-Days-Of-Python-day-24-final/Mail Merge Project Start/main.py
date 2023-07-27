
sl_file = "./Input/Letters/starting_letter.txt"
il_file = "./Input/Names/invited_names.txt"
PLACEHOLDER = "[name]"

with open(il_file, 'r') as il:
    invited_names_list = il.readlines()

with open(sl_file, 'r') as sl:
    starting_letter = sl.read()
    for name in invited_names_list:
        stripped_name = name.strip()
        new_letter = starting_letter.replace(PLACEHOLDER, stripped_name)
        with open(f"./Output/ReadyToSend/letter_for_{stripped_name}.txt", mode='w') as complete_letter:
            complete_letter.write(new_letter)
