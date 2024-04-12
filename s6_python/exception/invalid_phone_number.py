class invalid_phone_number(Exception):
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return(repr(self.value))

def validate(phone_number):
    if(len(phone_number) != 10):
        raise invalid_phone_number("Phone number must be 10 digits")
    else:
        print("Valid phone number")

try:
    validate("9191919191")
    validate("001001")
    validate("6776767676766")

except invalid_phone_number as e:
    print("Error: ", repr(e))