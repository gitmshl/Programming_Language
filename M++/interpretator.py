import mpp_exceptions
import web_commands
import docx_commands


modules = ["docx", "web"]
simple_key_words = [f"[{module}]" for module in modules] + web_commands.key_words + docx_commands.key_words
system_key_words = ["using"]


def get_margin_line(line, env):
    margin = env['__scope__'] * env['__init__']['margin']
    line_ = line[margin:]
    return margin, line_


def interpret_simple_command(line, line_number, env):
    
    def get_module(line, line_number):
        if line[0] != '[' or line.find(']') == -1:
            return env["module"]
        module_ = line[1:line.find(']')]
        for x in modules:
            if module_ == x:
                return module_
        raise mpp_exceptions.ModuleNotFound(line, line_number)

    line_ = get_margin_line(line, env)[1]
    module = get_module(line_, line_number)
    if module == "docx":
        docx_commands.interpret_simple_command(line_, line_number, env)
    elif module == "web":
        web_commands.interpret_simple_command(line_, line_number, env)


# возвращает номер последней строки, которую выполнил
def interpret_for_command(line, line_number, commands, env):

    def parse_for_expr():
        line_list = line.split()
        var_name = line_list[1]
        if var_name in env:
            raise mpp_exceptions.DoubleVarUse(line, line_number)
        lst = line_list[3].strip().split("->")
        if len(lst) == 1:
            driver = "driver__default__"
            xpath = lst[0]
        elif len(lst) == 2:
            driver = lst[0]
            if driver not in env:
                raise mpp_exceptions.DriverNotFound(line, line_number)
            xpath = lst[1]
        else:
            raise mpp_exceptions.SyntaxError(line, line_number)
        return var_name, driver, xpath
    
    
    def end_for(line, start, commands, env):
        length = len(commands)
        end = start
        pattern = ' ' * ((env['__scope__'] + 1) * env['__init__']['margin'])
        pattern_len = len(pattern)
        while end < length:
            if len(commands[end]) <= pattern_len or not commands[end][:pattern_len] == pattern:
                break
            end += 1
        return start, end - 1

    var_name, driver, xpath = parse_for_expr()
    start, end = end_for(line, line_number + 1, commands, env)
    env['__scope__'] += 1
    env['$_'] = 1
    for tmp in env[driver].find_elements_by_xpath(xpath):
        env[var_name] = tmp
        interpret(start, commands[:end+1], env)
        env['$_'] += 1

    env['__scope__'] -= 1
    del env[var_name]
    return end


def interpret_system_command(line, line_number, env):
    line_ = get_margin_line(line, env)[1]
    if line_[:5] == "using":
        if line_[5:].strip() not in modules:
            raise mpp_exceptions.ModuleNotFound(line, line_number)
        env["module"] = line_[5:].strip()
    

def get_command_global_type(line, line_number, env):

    def is_comment(line):
        return line.lstrip()[0] == '#'

    def is_simple_type(line, line_number):
        for key_word in simple_key_words:
            if line[:len(key_word)] == key_word:
                return True
        return False

    def is_system_type(line, line_number):
        for key_word in system_key_words:
            if line[:len(key_word)] == key_word:
                return True
        return False

    def is_for_type(line, line_number):
        if line[:3] != "for":
            return False
        line_lst = line.split()
        if len(line_lst) != 4:
            raise mpp_exceptions.SyntaxError(line, line_number, "Неверное количество параметров в цикле for.")
        if line_lst[2] != "in":
            raise mpp_exceptions.SyntaxError(line, line_number, "Отсутствует параметр 'in' в цикле for.")
        return True

    line_ = get_margin_line(line, env)[1]

    if is_comment(line) is True:
        return "comment"
    elif is_for_type(line_, line_number) is True:
        return "for"
    elif is_system_type(line_, line_number) is True:
        return "system"
    elif is_simple_type(line_, line_number) is True:
        return "simple"
    else:
        raise mpp_exceptions.UnknownGlobalType(line_, line_number)


def interpret(line_number, commands, env):
    length = len(commands)
    while line_number < length:
        line = commands[line_number].rstrip('\n')
        command_global_type = get_command_global_type(line, line_number, env)
    
        if command_global_type == "simple":
                interpret_simple_command(line, line_number, env)
        elif command_global_type == "for":
            line_number = interpret_for_command(line, line_number, commands, env)
        elif command_global_type == "system":
            interpret_system_command(line, line_number, env)

        line_number += 1


def main():
    filename = "main.mpp"
    try:
        with open(filename) as f:
            commands = f.readlines()
        env = {
            "__scope__": 0,
            "__init__": {
                "margin": 4
            },
            "$_": 1,    # переменная цикла (счетчик)
            "module": "web",
            "driver__default__": None,
            "docx_document__default__": (None, None)
        }
        line_number = 0
        interpret(line_number, commands, env)

    except mpp_exceptions.MyBaseException as e:
        print(e.what())


if __name__ == "__main__":
    main()