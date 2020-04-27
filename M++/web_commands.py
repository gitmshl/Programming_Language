from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import mpp_exceptions


key_words = ["load", "get"]


def com_load(line_lst, line, line_number, env):
    if len(line_lst) not in (2, 3):
        raise mpp_exceptions.SyntaxError(line, line_number, "Неверное число параметров.")
    if len(line_lst) == 3:
        driver_name, url = line_lst[1:]
    else:
        driver_name, url = "driver__default__", line_lst[1]
    
    if driver_name not in env or env[driver_name] is None:
        env[driver_name] = webdriver.Chrome()
    env[driver_name].get(url)


def com_get(line_lst, line, line_number, env):
    def get_varname_driver_rel_path():
        if len(line_lst) < 3:
            raise mpp_exceptions.SyntaxError(line, line_number, "Неверное число параметров.")
        if len(line_lst) >= 4:
            if line_lst[2][0] != '/':
                var_name, driver, rel_path = line_lst[1:]
            else:
                var_name = line_lst[1]
                driver = "driver__default__"
                rel_path = " ".join(line_lst[2:])
        else:
            var_name, rel_path = line_lst[1:]
            driver = "driver__default__"
        
        if driver not in env:
            raise mpp_exceptions.UnknownVar(line, line_number, driver)
        return var_name, driver, rel_path

    var_name, driver, rel_path = get_varname_driver_rel_path()

    tokens = rel_path.split('->')
    if len(tokens) > 2:
        raise mpp_exceptions.SyntaxError(line, line_number, "Неверно задан параметр relative-xpath(количество символов '->' больше 1)")
    if len(tokens) == 2:
        var, xpath = tokens
        if var not in env:
            raise mpp_exceptions.UnknownVar(line, line_number, var)
        tmp = env[var].find_elements_by_xpath(xpath)
    else:
        xpath = tokens[0]
        tmp = env[driver].find_elements_by_xpath(xpath)
    if len(tmp) == 0:
        raise mpp_exceptions.RuntimeError(line, line_number, "Количество найденных элементов в относительном xpath = 0")
    
    env[var_name] = tmp[0]


def interpret_simple_command(line, line_number, env):
    line_lst = line.split() if line[0] != '[' else line.split()[1:]
    command = line_lst[0]
    if command not in key_words:
        raise mpp_exceptions.UnknownCommand(line, line_number)
    if command == "load":
        com_load(line_lst, line, line_number, env)
    elif command == "get":
        com_get(line_lst, line, line_number, env)
    else:
        print("unknown command")