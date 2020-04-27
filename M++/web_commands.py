from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import mpp_exceptions


key_words = ["load"]


def com_load(line_lst, line, line_number, env):
    if len(line_lst) not in (2, 3):
        raise mpp_exceptions.SyntaxError(line, line_number, "Неверное число параметров.")
    if len(line_lst) == 3:
        driver_name, url = line_lst[1:]
        if driver_name in env:
            raise mpp_exceptions.DoubleVarUse(line, line_number)
    else:
        driver_name, url = "driver__default__", line_lst[1]
    
    env[driver_name] = webdriver.Chrome()
    env[driver_name].get(url)


def interpret_simple_command(line, line_number, env):
    line_lst = line.split() if line[0] != '[' else line.split()[1:]
    command = line_lst[0]
    if command not in key_words:
        raise mpp_exceptions.UnknownCommand(line, line_number)
    if command == "load":
        com_load(line_lst, line, line_number, env)
    else:
        print("unknown command")