# ask user which way to convert (C --> F, F --> C, C --> K, K --> C, F --> K, K --> F)
# if the direction is not recognized, print an error message
# ask user for the temp
# if they dont enter a number, print error message
# convert it
# print the result to 2dp
# wrap everything in a while loop
# reject temps below absolute zero

CONVERTERS = {
    "FC": "Fahrenheit to Celsius",
    "CF": "Celsius to Fahrenheit",
    "CK": "Celsius to Kelvins",
    "KC": "Kelvins to Celsius",
    "FK": "Fahrenheit to Kelvins",
    "KF": "Kelvins to Fahrenheit",        
}


def main():
    print("Temperature converter".upper().center(31, "="))
    
    while True:
        run_converter()
        
        close = close_converter()
        
        if close:
            break
    
    
def run_converter():
    show_converters()
    
    converter = user_select_converter()
    
    print("\n" + f"{CONVERTERS[converter.upper()]}")
    
    temp = user_enter_temp(converter)
    
    match converter:
        case "fc":
            answer = fahrenheit_to_celsius_converter(temp)
            print(f"\n{temp}°F is equivalent to {answer:.2f}°C\n")
                
        case "cf":
            answer = celsius_to_fahrenheit_converter(temp)
            print(f"\n{temp}°C is equivalent to {answer:.2f}°F\n")
            
        case "ck":
            answer = celsius_to_kelvins_converter(temp)
            print(f"\n{temp}°C is equivalent to {answer:.2f} K\n")
            
        case "kc":
            answer = kelvins_to_celsius_converter(temp)
            print(f"\n{temp} K is equivalent to {answer:.2f}°C\n")
            
        case "fk":
            answer = fahrenheit_to_kelvins_converter(temp)
            print(f"\n{temp}°F is equivalent to {answer:.2f} K\n")
        
        case "kf":
            answer = kelvins_to_fahrenheit_converter(temp)
            print(f"\n{temp} K is equivalent to {answer:.2f}°F\n")
                
        case _:
            print("\n...\n")
    
    
def show_converters():
    print("\nConverters:\n".upper())
    for key, converter in CONVERTERS.items():
        print(f"{key.upper()} > {converter}")
        
        
def user_select_converter():
    valid_choices = [key.casefold() for key in CONVERTERS.keys()]
    
    while True:
        user_choice = input("\nSelect a converter. Please enter (" + ", ".join(valid_choices) + "):\n>> ").strip().casefold()
    
        if user_choice in valid_choices:
            return user_choice
        else:
            print(f"\nInvalid entry. Please enter ({', '.join(valid_choices)}).\n")
            
            
def user_enter_temp(converter):
    while True:
        temp = input("\nEnter the temperature for conversion.\n>> ").strip()
        
        if is_number(temp):
            if not below_absolute_zero(converter, temp):
                return float(temp)
            else:
                print("\nThe temperature you entered is below absolute zero.")
        else:
            print("\nPlease enter a valid number.\n")
        
        
def is_number(num):
    try:
        float(num)
        return True
    except ValueError:
        return False
        
        
def below_absolute_zero(converter, temperature):
    match converter:
        case "cf" | "ck":
            return celsius_to_kelvins_converter(float(temperature)) < -1e-9
        case "fc" | "fk":
            return fahrenheit_to_kelvins_converter(float(temperature)) < -1e-9
        case "kc" | "kf":
            return float(temperature) < -1e-9
        case _:
            return False
        
        
def fahrenheit_to_celsius_converter(temperature):
    # C = (F - 32) * 5.0 / 9.0
    return (temperature - 32) * 5.0 / 9.0
        
        
def celsius_to_fahrenheit_converter(temperature):
    # F = C * 9.0 / 5.0 + 32
    return (temperature * 9.0 / 5.0) + 32
        
        
def kelvins_to_celsius_converter(temperature):
    return temperature - 273.15
    
    
def celsius_to_kelvins_converter(temperature):
    return temperature + 273.15
    
    
def fahrenheit_to_kelvins_converter(temperature):
    return fahrenheit_to_celsius_converter(temperature) + 273.15
    
    
def kelvins_to_fahrenheit_converter(temperature):
    return celsius_to_fahrenheit_converter(temperature - 273.15)
    
    
def close_converter():
    valid_entries = ["y", "n"]
    
    while True:
        close = input("\nClose converter? (y/n)\n>> ").strip().casefold()
        
        if close in valid_entries:
            return close == "y"
        else:
            print("Invalid entry. Please enter 'y' or 'n'. Try again.")
    
    
if __name__ == "__main__":
    main()
